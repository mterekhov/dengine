#ifndef SPCTGAME_AKEYBOARDCONTROLLER_H
#define SPCTGAME_AKEYBOARDCONTROLLER_H

//==============================================================================

#include "blockouttypes.h"
#include "agamestepscontroller.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class AKeyboardController
{
private:
    AGameStepsController& _gameStepsController;

public:
    AKeyboardController(AGameStepsController& gameStepsController);
    ~AKeyboardController();
    
    void keyPressed(TUint buttonCode);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AKEYBOARDCONTROLLER_H
