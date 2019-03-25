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
        
    TBool isBreakingWellBound(const APoint& position, const AFormation* formation, ASceneGraph &dataStorage);

    void moveCurrentFormationDown(ASceneGraph &dataStorage);
    void moveCurrentFormationUp(ASceneGraph &dataStorage);
    void moveCurrentFormationLeft(ASceneGraph &dataStorage);
    void moveCurrentFormationRight(ASceneGraph &dataStorage);
    
public:
    AFormationMoveGameStep(const TUint buttonCode);
    virtual ~AFormationMoveGameStep();
    
    virtual void executeStep(ASceneGraph &dataStorage);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AFORMATIONMOVEGAMESTEP_H
