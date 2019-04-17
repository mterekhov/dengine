#ifndef SPCTGAME_ABUTTONHANDLER_H
#define SPCTGAME_ABUTTONHANDLER_H

//==============================================================================

#include "apoint2d.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

class AButtonHandler
{
public:
    AButtonHandler();
    virtual ~AButtonHandler();
    
    virtual void handleTapEvent(const APoint2D& point, void *payLoad);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ABUTTONHANDLER_H
