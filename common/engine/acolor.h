#ifndef SPCTGAME_ACOLOR_H
#define SPCTGAME_ACOLOR_H

//==============================================================================

#include "blockouttypes.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
class AColor
{
public:
    static AColor whiteColor();
    static AColor blackColor();
    static AColor redColor();
    static AColor greenColor();
    static AColor blueColor();

    AColor();
    AColor(const TFloat _red, const TFloat _green, const TFloat _blue, const TFloat _alpha);
    AColor(const AColor& color);
    ~AColor();

    TFloat red;
    TFloat green;
    TFloat blue;
    TFloat alpha;
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ACOLOR_H
