#include "asize2d.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
ASize2D::ASize2D() : width(0.0f), height(0.0f)
{
}

//==============================================================================

ASize2D::ASize2D(const TFloat newWidth, const TFloat newHeight) : width(newWidth), height(newHeight)
{
}

//==============================================================================

ASize2D::ASize2D(const ASize2D& point)
{
    width = point.width;
    height = point.height;
}

//==============================================================================

ASize2D::~ASize2D()
{
}

//==============================================================================
    
}   //  namespace spcTGame
