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
#include "abutton.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
    AGame::AGame() : _renderService(_sceneGraph), _logic(_gameStepsController), _keyboardController(_gameStepsController), _currentMonsterNode(_sceneGraph.texturedNodes().end())
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

void AGame::generateMonster(const std::string& spriteName, spcWAD::ALevel& level)
{
    const spcWAD::ASprite& monsterSprite = level.findSprite(spriteName);
    const spcWAD::APicture& bossPicture = monsterSprite.findPicture(spriteName + "a1");
    AOpenGLTexture& monsterTexture = _sceneGraph._textureManager.createOrFindTexture(bossPicture.patchName(), bossPicture.imageData);
    
    if (_currentMonsterNode != _sceneGraph.texturedNodes().end())
    {
        _sceneGraph.removeObject(_currentMonsterNode);
    }

    _currentMonsterNode = _sceneGraph.addObject(new AMonster(monsterTexture), ESCENENODETYPE_TEXTURED, ESCENENODETRANSPARENCY_FULL);
    TFloat aspectHeight = static_cast<TFloat>(bossPicture.imageData.height()) / static_cast<TFloat>(monsterSprite.spriteHeight());
    TFloat aspectWidth = static_cast<TFloat>(bossPicture.imageData.width()) / static_cast<TFloat>(monsterSprite.spriteWidth());
    _currentMonsterNode->changeScale(AVector(1, aspectHeight, aspectWidth));
    
    //  attach animation
    AAnimation monsterTextureAnimation;
    monsterTextureAnimation._animationTrigger = 10;
    monsterTextureAnimation.appendChanger(new ASpriteChanger(monsterSprite, _sceneGraph._textureManager));
    _currentMonsterNode->attachAnimation(monsterTextureAnimation);
}

//==============================================================================

void AGame::startGame()
{
    spcWAD::AWAD wadResources(ABundle().fullPathToResource("doom.wad"));
    spcWAD::ALevel e1m8 = wadResources.readLevel("e1m8");
    spcWAD::TSpriteList monsters = e1m8.monstersList();

    //  create monster node
    generateMonster("boss", e1m8);

    //  create floor
    const spcWAD::AFlat& planeFlat = wadResources.findFlat("floor4_8");
    APlane *floorPlane = new APlane(_sceneGraph._textureManager.createOrFindTexture(planeFlat.flatName(), planeFlat.imageData()));
    floorPlane->planeSize = 80;
    TSceneNodesListIter newNode2 = _sceneGraph.addObject(floorPlane, ESCENENODETYPE_TEXTURED, ESCENENODETRANSPARENCY_NONE);
    newNode2->changePosition(APoint(-floorPlane->planeSize / 2.0f, 0.0f, -floorPlane->planeSize / 2.0f));

    createUIElements(wadResources);
    
    _logic.startGame();
}

//==============================================================================

void AGame::createUIElements(spcWAD::AWAD& wad)
{
    spcWAD::APicture picture = wad.readPicture("m_doom");
    picture.savePatchIntoTga("/Users/michael/Pictures/stbar.tga");
    AOpenGLTexture& hudTexture = _sceneGraph._textureManager.createOrFindTexture(picture.patchName(), picture.imageData);

    AButton *hud = new AButton(hudTexture);
    hud->buttonSize.width = static_cast<TFloat>(picture.imageData.width());
    hud->buttonSize.height = static_cast<TFloat>(picture.imageData.height());

    ASceneNode& newNode2 = _sceneGraph.addUIElement(hud, ESCENENODETRANSPARENCY_NONE);
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
    oglState->frustumSetup(screenWidth, screenHeight);
}

//==============================================================================
    
}   //  namespace spcTGame
