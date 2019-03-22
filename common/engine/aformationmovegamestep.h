#ifndef SPCTGAME_AFORMATIONMOVEGAMESTEP_H
#define SPCTGAME_AFORMATIONMOVEGAMESTEP_H

//==============================================================================

#include "agamestepprotocol.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class AFormationMoveGameStep : public AGameStepProtocol
{
private:
    TUint _buttonCode;
        
    TBool isBreakingWellBound(const APoint& position, const AFormation* formation, ADataStorage &dataStorage);

    void moveCurrentFormationDown(ADataStorage &dataStorage);
    void moveCurrentFormationUp(ADataStorage &dataStorage);
    void moveCurrentFormationLeft(ADataStorage &dataStorage);
    void moveCurrentFormationRight(ADataStorage &dataStorage);
    
public:
    AFormationMoveGameStep(const TUint buttonCode);
    virtual ~AFormationMoveGameStep();
    
    virtual void executeStep(ADataStorage &dataStorage);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AFORMATIONMOVEGAMESTEP_H
