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
    
    TBool isBreakingWellBound(const APoint& position, const AFormation* formation, ADataStorage &dataStorage);

    void rotateX(ADataStorage &dataStorage);
    void rotateY(ADataStorage &dataStorage);
    void rotateZ(ADataStorage &dataStorage);
    void rotate(const AMatrix& m, ADataStorage &dataStorage);

public:
    AFormationRotateGameStep(const TUint buttonCode);
    virtual ~AFormationRotateGameStep();
    
    virtual void executeStep(ADataStorage &dataStorage);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AFORMATIONROTATEGAMESTEP_H
