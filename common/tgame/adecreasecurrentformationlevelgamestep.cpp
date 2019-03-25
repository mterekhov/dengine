#include "adecreasecurrentformationlevelgamestep.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

ADecreaseCurrentFormationLevelGameStep::ADecreaseCurrentFormationLevelGameStep()
{
}

//==============================================================================

ADecreaseCurrentFormationLevelGameStep::~ADecreaseCurrentFormationLevelGameStep()
{
}

//==============================================================================

void ADecreaseCurrentFormationLevelGameStep::executeStep(ASceneGraph &dataStorage)
{
    AFormation *currentFormation = dataStorage.currentFormation();
    APoint currentFormationPosition = currentFormation->gridSpacePosition();
    currentFormationPosition.y -= 1.0f;
    currentFormation->gridSpacePosition(currentFormationPosition);
}

//==============================================================================

}   //  namespace spcTGame
