#include "afrustumborder.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

AFrustumBorder::AFrustumBorder() : x(0.0f), y(0.0f), z(0.0f)
{
}

//==============================================================================

AFrustumBorder::AFrustumBorder(const TFloat x, const TFloat y, const TFloat z) : x(x), y(y), z(z)
{
}

//==============================================================================

AFrustumBorder::AFrustumBorder(const AFrustumBorder& border)
{
    x = border.x;
    y = border.y;
    z = border.z;
}

//==============================================================================

}   //  namespace spcTGame
