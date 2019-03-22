#ifndef SPCTGAME_AMATRIX_H
#define SPCTGAME_AMATRIX_H

//==============================================================================

#include "blockouttypes.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
class AMatrix
{
public:
    TFloat m[4][4];
    
    static AMatrix rotationX(const TFloat angle);
    static AMatrix rotationY(const TFloat angle);
    static AMatrix rotationZ(const TFloat angle);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AMATRIX_H
