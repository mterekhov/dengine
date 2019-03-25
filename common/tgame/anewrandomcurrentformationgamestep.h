#ifndef SPCTGAME_ANEWRANDOMCURRENTFORMATIONGAMESTEP_H
#define SPCTGAME_ANEWRANDOMCURRENTFORMATIONGAMESTEP_H

//==============================================================================

#include "agamestepprotocol.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ANewRandomCurrentFormationGameStep : public AGameStepProtocol
{
public:
    ANewRandomCurrentFormationGameStep();
    virtual ~ANewRandomCurrentFormationGameStep();
    
    virtual void executeStep(ASceneGraph &dataStorage);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ANEWRANDOMCURRENTFORMATIONGAMESTEP_H
