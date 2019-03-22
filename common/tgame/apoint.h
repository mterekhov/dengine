#ifndef SPCTGAME_APOINT_H
#define SPCTGAME_APOINT_H

//==============================================================================

#include <vector>
#include "blockouttypes.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
class APoint
{
public:
    APoint();
    APoint(const TFloat x, const TFloat y, const TFloat z);
    APoint(const APoint& point);
    ~APoint();

    TFloat x;
    TFloat y;
    TFloat z;
};

//==============================================================================

typedef std::vector<APoint> TPointsList;

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_APOINT_H
