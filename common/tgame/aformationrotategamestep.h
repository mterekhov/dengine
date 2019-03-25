#ifndef SPCTGAME_AFORMATIONROTATEGAMESTEP_H
#define SPCTGAME_AFORMATIONROTATEGAMESTEP_H

//==============================================================================

#include "agamestepprotocol.h"
#include "amatrix.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class AFormationRotateGameStep : public AGameStepProtocol
{
private:
    TUint _buttonCode;
    
    TBool isBreakingWellBound(const APoint& position, const AFormation* formation, ASceneGraph &dataStorage);

    void rotateX(ASceneGraph &dataStorage);
    void rotateY(ASceneGraph &dataStorage);
    void rotateZ(ASceneGraph &dataStorage);
    void rotate(const AMatrix& m, ASceneGraph &dataStorage);

public:
    AFormationRotateGameStep(const TUint buttonCode);
    virtual ~AFormationRotateGameStep();
    
    virtual void executeStep(ASceneGraph &dataStorage);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AFORMATIONROTATEGAMESTEP_H
