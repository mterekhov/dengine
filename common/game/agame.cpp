#include "agame.h"
#include "adrawbasics.h"
#include "aopenglstate.h"
#include "blockoutdebug.h"
#include "aoglwrapper.h"
#include "amonster.h"
#include "abundle.h"
#include "alevel.h"
#include "types.h"
#include "aplane.h"
#include "aflat.h"
#include "aanimationbuilder.h"
#include "aspritechanger.h"
#include "aopenglsprite.h"

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

    const spcWAD::ASprite& bossSprite = e1m8.findSprite("sarg");

    //  create monster node
    const spcWAD::APicture& bossPicture = bossSprite.findPicture("sarga1");
    TFloat aspectHeight = static_cast<TFloat>(bossPicture.imageData.height()) / static_cast<TFloat>(bossSprite.spriteHeight());
    TFloat aspectWidth = static_cast<TFloat>(bossPicture.imageData.width()) / static_cast<TFloat>(bossSprite.spriteWidth());
    AOpenGLTexture& monsterTexture = _sceneGraph._textureManager.createOrFindTexture(bossPicture.patchName(), bossPicture.imageData);
    ASceneNode& newNode = _sceneGraph.addObject(new AMonster(monsterTexture), ESCENENODETYPE_TEXTURED, ESCENENODETRANSPARENCY_FULL);
    newNode.changeScale(AVector(1, aspectHeight, aspectWidth));
    
    //  attach animation
    AAnimation monsterTextureAnimation;
    monsterTextureAnimation._animationTrigger = 5;
    monsterTextureAnimation.appendChanger(new ASpriteChanger(bossSprite, _sceneGraph._textureManager));
    newNode.attachAnimation(monsterTextureAnimation);

    //  create floor
    const spcWAD::AFlat& planeFlat = wadResources.findFlat("floor4_8");
    APlane *floorPlane = new APlane(_sceneGraph._textureManager.createOrFindTexture(planeFlat.flatName(), planeFlat.imageData()));
    floorPlane->planeSize = 80;
    ASceneNode& newNode2 = _sceneGraph.addObject(floorPlane, ESCENENODETYPE_TEXTURED, ESCENENODETRANSPARENCY_NONE);
    newNode2.changePosition(APoint(-floorPlane->planeSize / 2.0f, 0.0f, -floorPlane->planeSize / 2.0f));

    createUIElements(wadResources);
    
    _logic.startGame();
}

//==============================================================================

void AGame::createUIElements(spcWAD::AWAD& wad)
{
    spcWAD::APicture picture = wad.readPicture("stbar");
    picture.savePatchIntoTga("/Users/michael/Pictures/stbar.tga");
    AOpenGLTexture& hudTexture = _sceneGraph._textureManager.createOrFindTexture(picture.patchName(), picture.imageData);
    AOpenGLSprite *hud = new AOpenGLSprite(hudTexture);
    hud->planeSize.width = 1;
    hud->planeSize.height = static_cast<TFloat>(picture.imageData.height()) / static_cast<TFloat>(picture.imageData.width());

    ASceneNode& newNode2 = _sceneGraph.addUIElement(hud, ESCENENODETRANSPARENCY_NONE);
    
//    newNode2.changePosition(APoint(-floorPlane->planeSize / 2.0f, 0.0f, -floorPlane->planeSize / 2.0f));
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

void AGame::updateScreenSize(const TFloat screenWidth, const TFloat screenHeight)
{
    AOpenGLState* oglState = spcTGame::AOpenGLState::shared();
    oglState->frustumSetup(screenWidth, screenHeight, false);
}

//==============================================================================
    
}   //  namespace spcTGame
