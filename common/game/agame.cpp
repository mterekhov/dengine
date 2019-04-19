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
#include "abanner.h"

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
    spcWAD::ALevel e1m8 = wadResources.readLevel("e2m6");
    spcWAD::TSpriteList monsters = e1m8.monstersList();

    //  create floor
    const spcWAD::AFlat& planeFlat = wadResources.findFlat("floor4_8");
    APlane *floorPlane = new APlane(_sceneGraph._textureManager.createOrFindTexture(planeFlat.flatName(), planeFlat.imageData()));
    floorPlane->planeSize = 80;
    TSceneNodesListIter newNode2 = _sceneGraph.addObject(floorPlane, ESCENENODETYPE_TEXTURED, ESCENENODETRANSPARENCY_NONE);
    newNode2->changePosition(APoint(-floorPlane->planeSize / 2.0f, 0.0f, -floorPlane->planeSize / 2.0f));

    createUIElements(e1m8, wadResources);
    
    _logic.startGame();
}

//==============================================================================

void AGame::createUIElements(const spcWAD::ALevel& level, spcWAD::AWAD& wad)
{
    TFloat leftShift = 20.0f;
    TFloat topShift = 20.0f;
    spcWAD::APicture doomLogoPicture = wad.readPicture("m_doom");
    TFloat menuWidth = doomLogoPicture.imageData.width();
    TFloat menuHeight = 500;

    ASize2D menuSize(menuWidth, menuHeight);
    const spcWAD::AFlat& menuBackgroundFlat = wad.findFlat("FLOOR4_6");
    AOpenGLTexture& menuBackgroundTexture = _sceneGraph._textureManager.createOrFindTexture(menuBackgroundFlat.flatName(), menuBackgroundFlat.imageData());
    ABanner *menu = new ABanner(menuBackgroundTexture);
    menu->bannerSize = menuSize;
    menu->bannerPosition = APoint2D(leftShift, topShift);
    _sceneGraph.addUIElement(menu);

    AOpenGLTexture& doomLogoTexture = _sceneGraph._textureManager.createOrFindTexture(doomLogoPicture.patchName(), doomLogoPicture.imageData);
    ABanner *doomLogo = new ABanner(doomLogoTexture);
    doomLogo->bannerSize = ASize2D(menuWidth, doomLogoPicture.imageData.height());
    doomLogo->bannerPosition = APoint2D(leftShift, menuHeight - doomLogoPicture.imageData.height());
    _sceneGraph.addUIElement(doomLogo);

    spcWAD::TSpriteList monstersList = level.monstersList();
    spcWAD::TSpriteListIter iter = monstersList.begin();

    spcWAD::APicture picture = wad.readPicture(iter->spritesPrefix + "a1");
    TFloat spaceBetween = 20.0f;
    APoint2D buttonPosition(leftShift, doomLogo->bannerPosition.y - spaceBetween);
    TFloat sizeScale = 1.0f;
    ASize2D buttonSize(picture.imageData.width() * sizeScale, picture.imageData.height() * sizeScale);
    AButton *hud = 0;
    const spcWAD::AFlat& buttonBackground = wad.findFlat("flat20");
    AOpenGLTexture& buttonBackgroundTexture = _sceneGraph._textureManager.createOrFindTexture(buttonBackground.flatName(), buttonBackground.imageData());
    for (;iter != monstersList.end(); iter++)
    {
        picture = wad.readPicture(iter->spritesPrefix + "a1");
        AOpenGLTexture& hudTexture = _sceneGraph._textureManager.createOrFindTexture(picture.patchName(), picture.imageData);

        hud = new AButton(hudTexture);
        hud->handler = this;
        hud->payLoad = new std::string(iter->spritesPrefix);

        hud->buttonSize = buttonSize;
        buttonPosition.y -= hud->buttonSize.height;
        buttonPosition.y -= spaceBetween;
        hud->buttonPosition = buttonPosition;
        hud->assignBackgroundTexture(buttonBackgroundTexture);

        _sceneGraph.addUIElement(hud);
    }
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

void AGame::processMouseEvent(const APoint2D& point)
{
    TSceneNodesList& uiElements = _sceneGraph.uiElementsNodes();
    for (TSceneNodesListIter iter = uiElements.begin(); iter != uiElements.end(); iter++)
    {
        AButton *button = static_cast<AButton *>(iter->nodeObject());
        button->processEvent(point);
    }
}

//==============================================================================

void AGame::updateScreenSize(const TFloat screenWidth, const TFloat screenHeight)
{
    AOpenGLState* oglState = spcTGame::AOpenGLState::shared();
    oglState->frustumSetup(screenWidth, screenHeight);
}

//==============================================================================
    
void AGame::handleTapEvent(const APoint2D& point, void *payLoad)
{
    std::string *character = static_cast<std::string *>(payLoad);
    printf("%.3f\t%.3f\t%s\n", point.x, point.y, character->c_str());
    //  create monster node
    spcWAD::AWAD wadResources(ABundle().fullPathToResource("doom.wad"));
    spcWAD::ALevel e1m8 = wadResources.readLevel("e2m6");
    generateMonster(*character, e1m8);
}

//==============================================================================

}   //  namespace spcTGame
