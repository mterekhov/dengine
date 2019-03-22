#ifndef SPCTGAME_ABUNDLE_H
#define SPCTGAME_ABUNDLE_H

//==============================================================================

#include "blockouttypes.h"
#include "abundleprotocol.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ABundle : public ABundleProtocol
{
private:
    ABundleProtocol *_bundle;
    
public:
    ABundle();
    virtual ~ABundle();
    
    virtual TString fullPathToResource(const TString& resourceFileName);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ABUNDLE_H
