#ifndef SPCTGAME_ADECREASECURRENTFORMATIONLEVELGAMESTEP_H
#define SPCTGAME_ADECREASECURRENTFORMATIONLEVELGAMESTEP_H

//==============================================================================

#include "agamestepprotocol.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ADecreaseCurrentFormationLevelGameStep : public AGameStepProtocol
{
public:
    ADecreaseCurrentFormationLevelGameStep();
    virtual ~ADecreaseCurrentFormationLevelGameStep();
    
    virtual void executeStep(ADataStorage &dataStorage);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ADECREASECURRENTFORMATIONLEVELGAMESTEP_H
