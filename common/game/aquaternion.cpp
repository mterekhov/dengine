#include "aquaternion.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

AQuaternion::AQuaternion() : _x(0.0f), _y(0.0f), _z(0.0f), _w(0.0f)
{
}

//==============================================================================

AQuaternion::AQuaternion(const AVector& vector, const TFloat angle)
{
    AVector v(vector);
    v.normalize();
    
    //  taske half of angle in radians
    TFloat half_angle = M_PI / 180.0f * angle * 0.5f;
    TFloat sin_a = sinf(half_angle);
    _x = v.x * sin_a;
    _y = v.y * sin_a;
    _z = v.z * sin_a;
    _w = cosf(half_angle);
}

//==============================================================================

AQuaternion::AQuaternion(const AQuaternion& quaternion) : _x(quaternion._x), _y(quaternion._y), _z(quaternion._z), _w(quaternion._w)
{
}

//==============================================================================

AQuaternion& AQuaternion::operator=(const AQuaternion& rv)
{
    if (this == &rv)
    {
        return *this;
    }
    
    _x = rv._x;
    _y = rv._y;
    _z = rv._z;
    _w = rv._w;

    return *this;
}

//==============================================================================

AQuaternion::~AQuaternion()
{
}

//==============================================================================

void AQuaternion::findVectorAndAngle(AVector& axis, TFloat& angle) const
{
    TFloat vectorLength = sqrtf(_x * _x + _y * _y + _z * _z);
    
    if (vectorLength > FLOAT_PRECISION)
    {
        TFloat invertedVectorLength = 1.0f / vectorLength;
        axis.x = _x * invertedVectorLength;
        axis.y = _y * invertedVectorLength;
        axis.z = _z * invertedVectorLength;
        
        if (_w < 0)
        {
            angle = 2.0f * atan2f(-vectorLength, -_w); //-PI,0
        }
        else
        {
            angle = 2.0f * atan2f(vectorLength, _w); //0,PI
        }
    }
    else
    {
        axis.x = 0;
        axis.y = 0;
        axis.z = 0;
        angle = 0;
    }
    
    //  return angle in degrees
    angle *= 180.0f / M_PI;
}

//==============================================================================

}   //  namespace spcTGame
