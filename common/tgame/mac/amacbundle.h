#ifndef SPCTGAME_AMACBUNDLE_H
#define SPCTGAME_AMACBUNDLE_H

//==============================================================================

#import "abundleprotocol.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class AMacBundle : public ABundleProtocol
{
public:
    virtual TString fullPathToResource(const TString& resourceFileName);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AMACBUNDLE_H
