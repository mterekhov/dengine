#ifndef SPCTGAME_AGAMESTEPSCONTROLLER_H
#define SPCTGAME_AGAMESTEPSCONTROLLER_H

//==============================================================================

#include <vector>

#include "agamestepprotocol.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

typedef std::vector<AGameStepProtocol*> TGameStepsQueue;
typedef TGameStepsQueue::iterator TGameStepsQueueIter;
typedef TGameStepsQueue::const_iterator TGameStepsQueueConstIter;

//==============================================================================

class AGameStepsController
{
private:
    TGameStepsQueue _stepsQueue;
    
    void destroyAllSteps();

public:
    AGameStepsController();
    ~AGameStepsController();
    void addStepToProcessQueue(AGameStepProtocol *gameStep);
    TUint processSteps(ASceneGraph& dataStorage);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AGAMESTEPSCONTROLLER_H
