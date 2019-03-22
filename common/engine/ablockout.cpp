#include "ablockout.h"
#include "adrawbasics.h"
#include "aopenglstate.h"
#include "awell.h"
#include "atexturedblock.h"
#include "asolidblock.h"
#include "aformationfactory.h"
#include "blockoutdebug.h"
#include "aoglwrapper.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
ABlockout::ABlockout() : _crafter(_dataStorage), _logic(_gameStepsController), _keyboardController(_gameStepsController)
{
    init();
}

//==============================================================================

ABlockout::~ABlockout()
{
}

//==============================================================================

void ABlockout::init()
{
    //  call shared to create instance and init some OpenGL pars;
    spcTGame::AOpenGLState::create();
}

//==============================================================================

void ABlockout::startGame()
{
    //  creates all the formations we need
    _logic.startGame();
    
    //  creating all the render lists to draw
    _crafter.refreshRenderLists();
}

//==============================================================================

void ABlockout::processGameCycle()
{
    _logic.processLogic();
    
    if (_gameStepsController.processSteps(_dataStorage) != 0)
        _crafter.refreshRenderLists();
        
    _crafter.processRender();
}

//==============================================================================
    
void ABlockout::processKeyboardEvent(const TUint buttonCode)
{
    _keyboardController.keyPressed(buttonCode);
}

//==============================================================================

void ABlockout::updateScreenSize(const TDouble screenWidth, const TDouble screenHeight)
{
    AOpenGLState* oglState = spcTGame::AOpenGLState::shared();
    oglState->frustumSetup(screenWidth, screenHeight);
}

//==============================================================================
    
}   //  namespace spcTGame
