#ifndef SPCTGAME_ASIZE2D_H
#define SPCTGAME_ASIZE2D_H

//==============================================================================

#include <vector>

#include "blockouttypes.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
class ASize2D
{
public:
    ASize2D();
    ASize2D(const TFloat x, const TFloat y);
    ASize2D(const ASize2D& point);
    ~ASize2D();

    TFloat width;
    TFloat height;
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ASIZE2D_H
