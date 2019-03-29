#include "amonster.h"
#include "adrawbasics.h"
#include "aopenglstate.h"
#include "aoglwrapper.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

AMonster::AMonster(ATexture& texture) : _texture(texture)
{
}

//==============================================================================

AMonster::~AMonster()
{
}

//==============================================================================
    
TPointsList AMonster::generatePlanePoints(const TFloat textureWidth, const TFloat textureHeight) const
{
    TPointsList pointList;
    
    TFloat monsterWidth = 1.0f;
    TFloat monsterHeight = 1.0f;
    if (textureWidth >= textureHeight)
    {
        monsterWidth = textureHeight / textureWidth;
    }
    else
    {
        monsterHeight = textureWidth / textureHeight;
    }
    
    APoint p1 = APoint();
    APoint p2 = APoint(p1.x, p1.y + monsterWidth, p1.z);  //p5
    APoint p3 = APoint(p1.x, p1.y + monsterWidth, p1.z + monsterHeight);  //p8
    APoint p4 = APoint(p1.x, p1.y,                p1.z + monsterHeight);  //p4
    
    pointList.push_back(p3);
    pointList.push_back(p1);
    pointList.push_back(p2);
    pointList.push_back(p3);
    pointList.push_back(p4);
    pointList.push_back(p1);
    
    return pointList;
}

//==============================================================================

TPoints2DList AMonster::generatePlaneUVPoints(const ATexture& texture) const
{
    TPoints2DList uvpointList;
    
    TFloat xaspect = static_cast<TFloat>(texture.imageWidth()) / static_cast<TFloat>(texture.width());
    TFloat yaspect = static_cast<TFloat>(texture.imageHeight()) / static_cast<TFloat>(texture.height());
    
    APoint2D t1 = APoint2D(0.0f, 0.0f);
    APoint2D t2 = APoint2D(0.0f, yaspect);
    APoint2D t3 = APoint2D(xaspect, yaspect);
    APoint2D t4 = APoint2D(xaspect, 0.0f);

    uvpointList.push_back(t4);
    uvpointList.push_back(t2);
    uvpointList.push_back(t1);

    uvpointList.push_back(t4);
    uvpointList.push_back(t3);
    uvpointList.push_back(t2);
    
    return uvpointList;
}

//==============================================================================

void AMonster::renderObject() const
{
    TPointsList coordspoints = generatePlanePoints(_texture.width(), _texture.height());
    TPoints2DList uvpoints = generatePlaneUVPoints(_texture);
    
    ADrawBasics::drawTexturedPlane(coordspoints, uvpoints, _texture);
}

//==============================================================================

}   //  namespace spcTGame
