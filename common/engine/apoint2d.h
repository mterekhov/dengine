#ifndef SPCTGAME_APOINT2D_H
#define SPCTGAME_APOINT2D_H

//==============================================================================

#include <vector>

#include "blockouttypes.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
class APoint2D
{
public:
    APoint2D();
    APoint2D(const TFloat x, const TFloat y);
    APoint2D(const APoint2D& point);
    ~APoint2D();

    TFloat x;
    TFloat y;
};

//==============================================================================

typedef std::vector<APoint2D> TPoints2DList;

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_APOINT2D_H
