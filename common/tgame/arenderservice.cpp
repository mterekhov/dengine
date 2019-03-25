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

ARenderService::ARenderService(ASceneGraph& dataStorage): _dataStorage(dataStorage)
{
}

//==============================================================================

ARenderService::~ARenderService()
{
    clearAllLists();
}

//==============================================================================

#pragma mark - Game events -

//==============================================================================

void ARenderService::refreshRenderLists()
{
    renewRenderLists();
}

//==============================================================================

#pragma mark - Routine -

//==============================================================================

void ARenderService::renewRenderLists()
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

void ARenderService::createDroppedBlocks()
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

AWell* ARenderService::createWell()
{
    AWell* well = new AWell(_dataStorage.wellFormation());
    addObjectForRender(well);
    
    return well;
}

//==============================================================================

#pragma mark - blocks creation -

//==============================================================================

ASolidBlock* ARenderService::createSolidBlock(AFormation* formation)
{
    ASolidBlock* newBlock = new ASolidBlock(formation);
    addObjectForRender(newBlock);
    
    return newBlock;
}

//==============================================================================

AColoredBlock* ARenderService::createColoredBlock(AFormation* formation)
{
    AColoredBlock* newBlock = new AColoredBlock(formation);
    addObjectForRender(newBlock);
    
    return newBlock;
}

//==============================================================================

ATexturedBlock* ARenderService::createTexturedBlock(AFormation* formation, const ATexture& texture)
{
    ATexturedBlock* newBlock = new ATexturedBlock(formation, texture);
    addObjectForRender(newBlock);
    
    return newBlock;
}

//==============================================================================

#pragma mark - render list management -

//==============================================================================

void ARenderService::generateTexturedRenderList(const TFormationList& formations, const ATexture& texture)
{
    for (TFormationListConstIter iter = formations.begin(); iter != formations.end(); iter++)
    {
        createTexturedBlock((*iter), texture);
    }
}

//==============================================================================

void ARenderService::clearAllLists()
{
    clearRenderList();
    clearTextureList();
}

//==============================================================================

void ARenderService::clearRenderList()
{
    if (!clearList(_solidRenderList))
    {
        loger("failed to clear solid objects list");
    }
}

//==============================================================================

void ARenderService::clearTextureList()
{
    if (!clearList(_texturedRenderList))
    {
        loger("failed to clear textured objects list");
    }
}

//==============================================================================

TBool ARenderService::clearList(TRObjectsList& renderList)
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

TBool ARenderService::addObjectForRender(ARObject* object)
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

void ARenderService::processRender()
{
    AOpenGLState* oglState = AOpenGLState::shared();
    oglState->clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    oglState->pushMarices();

    ADrawBasics::installCamera(AVector(5.0f, 5.0f, 5.0f),
                               AVector(0.0f, 0.0f, 0.0f),
                               AVector(1.0f, 0.0f, 0.0f));
 
    renderContent();

    oglState->popMarices();
}

//==============================================================================

void ARenderService::renderContent()
{
    AOpenGLState* oglState = AOpenGLState::shared();

    //  Draw solid list
    AColor previousColor = oglState->drawColor();
//    TRObjectsList listToRender = _solidRenderList;
//    renderList(listToRender);
//    oglState->drawColor(previousColor);
//
//    //  Draw textured objects
//    previousColor = oglState->drawColor();
//    oglState->drawColor(AColor::whiteColor());
//    oglState->textureEnable();
//    listToRender = _texturedRenderList;
//    renderList(listToRender);
//    oglState->textureDisable();
    oglState->drawColor(AColor::redColor());
    ADrawBasics::drawGrid(50, 50, 1);
    oglState->drawColor(previousColor);
}

//==============================================================================

void ARenderService::renderList(const TRObjectsList& renderList)
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
