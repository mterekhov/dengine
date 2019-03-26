#ifndef SPCTGAME_AGAMESTEPPROTOCOL_H
#define SPCTGAME_AGAMESTEPPROTOCOL_H

//==============================================================================
//
//  This class provides common functionality for any event which could happen in game
//
//==============================================================================

#include "ascenegraph.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class AGameStepProtocol
{
public:
    virtual void executeStep(ASceneGraph &sceneGraph) = 0;
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AGAMESTEPPROTOCOL_H
