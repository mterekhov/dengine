#ifndef SPCTGAME_ANODEOBJECT
#define SPCTGAME_ANODEOBJECT

//==============================================================================

#include "blockouttypes.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

class ANodeObject
{
public:
    ANodeObject();
    virtual ~ANodeObject();
    
    virtual void renderObject() const;
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ANODEOBJECT

