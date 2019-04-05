#include "arenderservice.h"
#include "aopenglstate.h"
#include "blockoutdebug.h"
#include "aoglwrapper.h"
#include "adrawbasics.h"
#include "abundle.h"
#include "ascenenode.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
#pragma mark - init -

//==============================================================================

ARenderService::ARenderService(ASceneGraph& sceneGraph): _sceneGraph(sceneGraph)
{
}

//==============================================================================

ARenderService::~ARenderService()
{
}

//==============================================================================

void ARenderService::processRender()
{
    AOpenGLState* oglState = AOpenGLState::shared();
    oglState->setupIsometricProjection();
    oglState->clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    oglState->pushMarices();
    ADrawBasics::installCamera(AVector(5, 1, 0),
                               AVector(0, 0, 0),
                               AVector(0, 1.0f, 0));

//    ADrawBasics::drawOrigin(APoint(0, 0, 0), 1);
//    ADrawBasics::drawGrid(50, 50, 1);

    //  render textured objects
    renderTexturedObjects();
    
    oglState->popMarices();
    
    oglState->setupOthoProjection();
    renderUI();
    
}

//==============================================================================

void ARenderService::renderUI()
{
    AOpenGLState *instance = AOpenGLState::shared();
    AColor previousColor = instance->drawColor();
    instance->drawColor(AColor::whiteColor());
    instance->textureEnable();

    TSceneNodesList& uielementsList = _sceneGraph.uiElementsNodes();
    TSceneNodesListIter iterBegin = uielementsList.begin();
    TSceneNodesListIter iterEnd = uielementsList.end();
    for (TSceneNodesListIter iter = iterBegin; iter != iterEnd; iter++)
    {
        ASceneNode &node = *iter;
        node.bindTexture();
        instance->pushMarices();
        instance->translate(node.position());
        instance->rotation(node.rotation());
        instance->scale(node.scale());
        node.renderObject();
        instance->popMarices();
    }

    instance->textureDisable();
    instance->drawColor(previousColor);
}
    
//==============================================================================

void ARenderService::renderTexturedObjects()
{
    AOpenGLState *instance = AOpenGLState::shared();
    AColor previousColor = instance->drawColor();
    instance->drawColor(AColor::whiteColor());
    instance->textureEnable();

    renderObjectWithTransparency(ESCENENODETRANSPARENCY_NONE);
    renderObjectWithTransparency(ESCENENODETRANSPARENCY_HALF);
    renderObjectWithTransparency(ESCENENODETRANSPARENCY_FULL);

    instance->textureDisable();
    instance->drawColor(previousColor);
}
    
//==============================================================================

void ARenderService::renderObjectWithTransparency(const ESceneNodeTrasnsparency nodeTransparency)
{
    AOpenGLState *instance = AOpenGLState::shared();
    TSceneNodesList& texturedObjectsList = _sceneGraph.texturedNodes();
    TSceneNodesListIter iterBegin = texturedObjectsList.begin();
    TSceneNodesListIter iterEnd = texturedObjectsList.end();
    for (TSceneNodesListIter iter = iterBegin; iter != iterEnd; iter++)
    {
        ASceneNode &node = *iter;
        if (node.transparencyType() != nodeTransparency)
        {
            continue;
        }
        
        node.bindTexture();
        instance->pushMarices();
        node.applyAnimation();
        
        instance->pushMarices();
        instance->translate(node.position());
        instance->rotation(node.rotation());
        instance->scale(node.scale());
        node.renderObject();
        instance->popMarices();
        instance->popMarices();
    }
}

//==============================================================================

}   //  namespace spcTGame
