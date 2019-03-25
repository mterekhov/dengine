#include "acrafter.h"
#include "aopenglstate.h"
#include "blockoutdebug.h"
#include "aoglwrapper.h"
#include "adrawbasics.h"
#include "abundle.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
#pragma mark - init -

//==============================================================================

ACrafter::ACrafter(ADataStorage& dataStorage): _dataStorage(dataStorage)
{
}

//==============================================================================

ACrafter::~ACrafter()
{
    clearAllLists();
}

//==============================================================================

#pragma mark - Game events -

//==============================================================================

void ACrafter::refreshRenderLists()
{
    renewRenderLists();
}

//==============================================================================

#pragma mark - Routine -

//==============================================================================

void ACrafter::renewRenderLists()
{
    clearAllLists();
    
    //  create well and add it to render cycle
    createWell();
    
    //  create current block and add it to render cycle
    createColoredBlock(_dataStorage.currentFormation());
    
    //  create render list for all dropped blocks
    createDroppedBlocks();
}

//==============================================================================

void ACrafter::createDroppedBlocks()
{
    const TFormationList& droppedFormations = _dataStorage.droppedFormationsList();
    for (TFormationListConstIter iter = droppedFormations.begin(); iter != droppedFormations.end(); iter++)
    {
        TString textureFileName = "celtic.tga";
        textureFileName = ABundle().fullPathToResource(textureFileName);
        createTexturedBlock(*iter, _textureManager.createTextureFromTGA(textureFileName));
    }
}

//==============================================================================

#pragma mark - create well -

//==============================================================================

AWell* ACrafter::createWell()
{
    AWell* well = new AWell(_dataStorage.wellFormation());
    addObjectForRender(well);
    
    return well;
}

//==============================================================================

#pragma mark - blocks creation -

//==============================================================================

ASolidBlock* ACrafter::createSolidBlock(AFormation* formation)
{
    ASolidBlock* newBlock = new ASolidBlock(formation);
    addObjectForRender(newBlock);
    
    return newBlock;
}

//==============================================================================

AColoredBlock* ACrafter::createColoredBlock(AFormation* formation)
{
    AColoredBlock* newBlock = new AColoredBlock(formation);
    addObjectForRender(newBlock);
    
    return newBlock;
}

//==============================================================================

ATexturedBlock* ACrafter::createTexturedBlock(AFormation* formation, const ATexture& texture)
{
    ATexturedBlock* newBlock = new ATexturedBlock(formation, texture);
    addObjectForRender(newBlock);
    
    return newBlock;
}

//==============================================================================

#pragma mark - render list management -

//==============================================================================

void ACrafter::generateTexturedRenderList(const TFormationList& formations, const ATexture& texture)
{
    for (TFormationListConstIter iter = formations.begin(); iter != formations.end(); iter++)
    {
        createTexturedBlock((*iter), texture);
    }
}

//==============================================================================

void ACrafter::clearAllLists()
{
    clearRenderList();
    clearTextureList();
}

//==============================================================================

void ACrafter::clearRenderList()
{
    if (!clearList(_solidRenderList))
    {
        loger("failed to clear solid objects list");
    }
}

//==============================================================================

void ACrafter::clearTextureList()
{
    if (!clearList(_texturedRenderList))
    {
        loger("failed to clear textured objects list");
    }
}

//==============================================================================

TBool ACrafter::clearList(TRObjectsList& renderList)
{
    if (renderList.size() == 0)
        return false;

    TRObjectsListConstIter iterBegin = renderList.begin();
    TRObjectsListConstIter iterEnd = renderList.end();
    for (TRObjectsListConstIter iter = iterBegin; iter != iterEnd; iter++)
        delete (*iter);
    
    renderList.clear();
    
    return true;
}

//==============================================================================

TBool ACrafter::addObjectForRender(ARObject* object)
{
    if (object == 0)
        return false;
    
    switch (object->objectType())
    {
        case OBJECTTYPE_SOLID:
            _solidRenderList.push_back(object);
        break;
            
        case OBJECTTYPE_TEXTURED:
            _texturedRenderList.push_back(object);
        break;
        
        default:
            return false;
    }
    
    return true;
}

//==============================================================================

#pragma mark - craft the list -

//==============================================================================

void ACrafter::processRender()
{
    AOpenGLState* oglState = AOpenGLState::shared();
    oglState->clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    oglState->pushMarices();

    TFloat wWidth = _dataStorage.wellWidth();
    TFloat wHeight = _dataStorage.wellHeight();
    TFloat wDepth = _dataStorage.wellDepth();
    ADrawBasics::installCamera(AVector(wHeight / 2.0f, 2.0f * wDepth, wWidth / 2.0f),
                               AVector(wHeight / 2.0f, 0.0f, wWidth / 2.0f),
                               AVector(1.0f, 0.0f, 0.0f));
 
    renderContent();

    oglState->popMarices();
}

//==============================================================================

void ACrafter::renderContent()
{
    AOpenGLState* oglState = AOpenGLState::shared();

    //  Draw solid list
    AColor previousColor = oglState->drawColor();
    TRObjectsList listToRender = _solidRenderList;
    renderList(listToRender);
    oglState->drawColor(previousColor);

    //  Draw textured objects
    previousColor = oglState->drawColor();
    oglState->drawColor(AColor::whiteColor());
    oglState->textureEnable();
    listToRender = _texturedRenderList;
    renderList(listToRender);
    oglState->textureDisable();
    oglState->drawColor(previousColor);
}

//==============================================================================

void ACrafter::renderList(const TRObjectsList& renderList)
{
    if (renderList.size() == 0)
        return;

    TRObjectsListConstIter iterBegin = renderList.begin();
    TRObjectsListConstIter iterEnd = renderList.end();
    for (TRObjectsListConstIter iter = iterBegin; iter != iterEnd; iter++)
        (*iter)->renderObject();
}

//==============================================================================
    
}   //  namespace spcTGame
