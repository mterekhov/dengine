#ifndef SPCTGAME_ABUNDLEPROTOCOL_H
#define SPCTGAME_ABUNDLEPROTOCOL_H

//==============================================================================

#include "blockouttypes.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ABundleProtocol
{
public:
    virtual TString fullPathToResource(const TString& resourceFileName) = 0;
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ABUNDLEPROTOCOL_H
