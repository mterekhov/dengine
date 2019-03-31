#ifndef SPCTGAME_AQUATERNION_H
#define SPCTGAME_AQUATERNION_H

//==============================================================================

#include "blockouttypes.h"
#include "avector.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

class AQuaternion
{
private:
    TFloat _x;
    TFloat _y;
    TFloat _z;
    TFloat _w;

public:
    AQuaternion();
    AQuaternion(const AVector& vector, const TFloat angle);
    AQuaternion(const AQuaternion& quaternion);
    AQuaternion& operator=(const AQuaternion& rv);
    ~AQuaternion();

    void findVectorAndAngle(AVector& axis, TFloat& angle) const;
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ACOLOR_H
