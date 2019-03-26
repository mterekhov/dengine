#include "agame.h"
#include "adrawbasics.h"
#include "aopenglstate.h"
#include "blockoutdebug.h"
#include "aoglwrapper.h"
#include "amonster.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
AGame::AGame() : _renderService(_sceneGraph), _logic(_gameStepsController), _keyboardController(_gameStepsController)
{
    init();
}

//==============================================================================

AGame::~AGame()
{
}

//==============================================================================

void AGame::init()
{
    //  call shared to create instance and init some OpenGL pars;
    spcTGame::AOpenGLState::create();
}

//==============================================================================

void AGame::startGame()
{
    //  creates all the formations we need
    
//    _sceneGraph.addObject(AMonster());
    
    
    _logic.startGame();
}

//==============================================================================

void AGame::processGameCycle()
{
    _logic.processLogic();
    
//    if (_gameStepsController.processSteps(_sceneGraph) != 0)
//        _renderService.refreshRenderLists();
        
    _renderService.processRender();
}

//==============================================================================
    
void AGame::processKeyboardEvent(const TUint buttonCode)
{
    _keyboardController.keyPressed(buttonCode);
}

//==============================================================================

void AGame::updateScreenSize(const TDouble screenWidth, const TDouble screenHeight)
{
    AOpenGLState* oglState = spcTGame::AOpenGLState::shared();
    oglState->frustumSetup(screenWidth, screenHeight);
}

//==============================================================================
    
}   //  namespace spcTGame
