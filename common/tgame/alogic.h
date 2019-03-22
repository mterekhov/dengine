#ifndef SPCTGAME_ALOGIC_H
#define SPCTGAME_ALOGIC_H

//==============================================================================

#include "agamestepscontroller.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

#define LEVEL_DEC_PERIOD 1

//==============================================================================
    
class ALogic
{
private:
    time_t _previousCycleTimeStamp;
	AGameStepsController &_gameStepsController;
	
public:
    ALogic(AGameStepsController& gameStepsController);
    virtual ~ALogic();

    void startGame();
    void processLogic();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ALOGIC_H
