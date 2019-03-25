#include "agamestepscontroller.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

AGameStepsController::AGameStepsController()
{
}

//==============================================================================

AGameStepsController::~AGameStepsController()
{
}

//==============================================================================

void AGameStepsController::addStepToProcessQueue(AGameStepProtocol *gameStep)
{
    if (gameStep == 0)
        return;
    
    _stepsQueue.push_back(gameStep);
}

//==============================================================================

TUint AGameStepsController::processSteps(ASceneGraph& dataStorage)
{
    printf("start %i steps execution ... ", _stepsQueue.size());
    
    TUint stepsProcessed = 0;
    for (TGameStepsQueueIter iter = _stepsQueue.begin(); iter != _stepsQueue.end(); iter++)
    {
        AGameStepProtocol *step = *iter;
        step->executeStep(dataStorage);
        delete step;
        stepsProcessed++;
    }

    _stepsQueue.clear();
    printf("finished\n");
    
    return stepsProcessed;
}

//==============================================================================

void AGameStepsController::destroyAllSteps()
{
    for (TGameStepsQueueIter iter = _stepsQueue.begin(); iter != _stepsQueue.end(); iter++)
        delete *iter;
    
    _stepsQueue.clear();
}

//==============================================================================

}   //  namespace spcTGame
