#ifndef SPCTGAME_AVECTOR_H
#define SPCTGAME_AVECTOR_H

//==============================================================================

#include "blockouttypes.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
class AVector
{
public:
    AVector();
    AVector(const TFloat x, const TFloat y, const TFloat z);
    AVector(const AVector& vector);
    ~AVector();
    
    void normalize();

    TFloat x;
    TFloat y;
    TFloat z;
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AVECTOR_H
