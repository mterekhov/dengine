#include "agame.h"
#include "adrawbasics.h"
#include "aopenglstate.h"
#include "blockoutdebug.h"
#include "aoglwrapper.h"
#include "amonster.h"
#include "abundle.h"
#include "awad.h"
#include "alevel.h"
#include "types.h"

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
    spcWAD::AWAD wadResources(ABundle().fullPathToResource("doom.wad"));
    spcWAD::ALevel e1m8 = wadResources.readLevel("e1m8");
    const spcWAD::ASprite& bossSprite = e1m8.findSprite("troo");

    const spcWAD::APicture& bossPicture = bossSprite.findPicture("trooa1");
    spcWAD::AImageData image = bossPicture.imageData;
    AImage gameImage(bossPicture.patchName(), image.data(), image.width(), image.height(), 24);
    ATexture& monsterTexture = _sceneGraph._textureManager.createOrFindTexture(gameImage);
    _sceneGraph.addObject(new AMonster(monsterTexture), APoint(), NODETYPE_TEXTURED);
    
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
