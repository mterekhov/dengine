#ifndef SPCTGAME_ACREATEWELLGAMESTEP_H
#define SPCTGAME_ACREATEWELLGAMESTEP_H

//==============================================================================

#include "agamestepprotocol.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ACreateWellGameStep : public AGameStepProtocol
{
private:
    APoint findDropPosition(AFormation* formation);
    
public:
    ACreateWellGameStep();
    virtual ~ACreateWellGameStep();
    
    virtual void executeStep(ASceneGraph &dataStorage);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ACREATEWELLGAMESTEP_H
