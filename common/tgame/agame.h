#ifndef SPCTGAME_ABLOCKOUT_H
#define SPCTGAME_ABLOCKOUT_H

//==============================================================================

#include "acrafter.h"
#include "alogic.h"
#include "acolor.h"
#include "akeyboardcontroller.h"
#include "adatastorage.h"
#include "agamestepscontroller.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

class AGame
{
private:
    void init();
    void render();

    ASceneGraph _dataStorage;
    ARenderService _crafter;
    ALogic _logic;
    AKeyboardController _keyboardController;
    AGameStepsController _gameStepsController;
        
public:
    AGame();
    ~AGame();
    
    void updateScreenSize(const TDouble screenWidth, const TDouble screenHeight);
    
    void startGame();
    void processKeyboardEvent(const TUint buttonCode);
    void processGameCycle();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ABLOCKOUT_H
