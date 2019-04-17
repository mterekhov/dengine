#ifndef SPCTGAME_ABLOCKOUT_H
#define SPCTGAME_ABLOCKOUT_H

//==============================================================================

#include "ascenegraph.h"
#include "arenderservice.h"
#include "alogic.h"
#include "akeyboardcontroller.h"
#include "agamestepscontroller.h"
#include "awad.h"
#include "abuttonhandler.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

class AMonster;

//==============================================================================

class AGame : public AButtonHandler
{
private:
    void init();
    void render();
    void createUIElements(spcWAD::AWAD& wad);
    void generateMonster(const std::string& spriteName, spcWAD::ALevel& level);

    ASceneGraph _sceneGraph;
    ARenderService _renderService;
    ALogic _logic;
    AKeyboardController _keyboardController;
    AGameStepsController _gameStepsController;
    
    TSceneNodesListIter _currentMonsterNode;
public:
    AGame();
    ~AGame();
    
    void updateScreenSize(const TFloat screenWidth, const TFloat screenHeight);
    void startGame();
    void processKeyboardEvent(const TUint buttonCode);
    void processMouseEvent(const APoint2D& point);
    void processGameCycle();
    
    virtual void handleTapEvent(const APoint2D& point, void *payLoad);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ABLOCKOUT_H
