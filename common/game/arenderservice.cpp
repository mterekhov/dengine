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
    ADrawBasics::installCamera(AVector(5.0f, 2.f, 0.0f),
                               AVector(0.0f, 0.0f, 0.0f),
                               AVector(0.0f, 1.0f, 0.0f));
//    ADrawBasics::installCamera(AVector(-4.0f, 0.5f, 0.5f),
//                               AVector(0.0f, 0.0f, 0.0f),
//                               AVector(0.0f, 1.0f, 0.0f));

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
    
    const TSceneNodesList& texturedObjectsList = _sceneGraph.texturedNodes();
    TSceneNodesListConstIter iterBegin = texturedObjectsList.begin();
    TSceneNodesListConstIter iterEnd = texturedObjectsList.end();
    for (TSceneNodesListConstIter iter = iterBegin; iter != iterEnd; iter++)
    {
        instance->pushMarices();
        instance->translate(iter->position());
        const ASceneNode &node = *iter;
        node.nodeObject()->renderObject();
        instance->popMarices();
    }
    
    
    instance->textureDisable();
    instance->drawColor(previousColor);
}
    
//==============================================================================

}   //  namespace spcTGame
