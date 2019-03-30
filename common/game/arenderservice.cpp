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
    ADrawBasics::installCamera(AVector(2.0f, 2.f, 0.5f),
                               AVector(0.0f, 0.0f, 0.0f),
                               AVector(0.0f, 1.0f, 0.0f));

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
    const TSceneNodesList& texturedObjectsList = _sceneGraph.texturedNodes();
    TSceneNodesListConstIter iterBegin = texturedObjectsList.begin();
    TSceneNodesListConstIter iterEnd = texturedObjectsList.end();
    for (TSceneNodesListConstIter iter = iterBegin; iter != iterEnd; iter++)
    {
        const ASceneNode &node = *iter;
        if (node.transparencyType() != nodeTransparency)
        {
            continue;
        }
        
        instance->pushMarices();
        instance->translate(iter->position());
        node.nodeObject()->renderObject();
        instance->popMarices();
    }

}

//==============================================================================

}   //  namespace spcTGame
