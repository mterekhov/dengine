#include "arenderservice.h"
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
    ADrawBasics::installCamera(AVector(5.0f, 5.0f, 5.0f),
                               AVector(1.0f, 1.0f, 1.0f),
                               AVector(0.0f, 1.0f, 0.0f));

    ADrawBasics::drawGrid(50, 50, 1);
    
    oglState->popMarices();
}

//==============================================================================

void ARenderService::renderContent()
{
}
    
//==============================================================================

}   //  namespace spcTGame
