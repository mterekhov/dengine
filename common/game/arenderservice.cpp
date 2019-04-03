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
    oglState->clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    oglState->pushMarices();
    ADrawBasics::installCamera(AVector(5, 1, 0),
                               AVector(0, 0, 0),
                               AVector(0, 1.0f, 0));

    ADrawBasics::drawGrid(50, 50, 1);
    //  render textured objects
    renderTexturedObjects();
    
    oglState->popMarices();
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
        
        instance->pushMarices();
        instance->scale(node.scale());
        instance->rotation(node.rotation());
        instance->translate(node.position());
        node.bindTexture();
        node.applyAnimation();
        node.renderObject();
        instance->popMarices();
    }

}

//==============================================================================

}   //  namespace spcTGame
