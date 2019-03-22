#ifndef SPCTGAME_AFORMATIONDROPGAMESTEP_H
#define SPCTGAME_AFORMATIONDROPGAMESTEP_H

//==============================================================================

#include "agamestepprotocol.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class AFormationDropGameStep : public AGameStepProtocol
{
private:
    APoint findDropPosition(AFormation* formation);
    
public:
    AFormationDropGameStep();
    virtual ~AFormationDropGameStep();
    
    virtual void executeStep(ADataStorage &dataStorage);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AFORMATIONDROPGAMESTEP_H
