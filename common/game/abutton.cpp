#include "abutton.h"
#include "adrawbasics.h"
#include "aopenglstate.h"
#include "aoglwrapper.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

AButton::AButton(AOpenGLTexture& texture) : _texture(texture), buttonSize(0, 0), payLoad(0)
{
}

//==============================================================================

AButton::~AButton()
{
}

//==============================================================================
    
TPoints2DList AButton::generatePlaneUVPoints(const AOpenGLTexture& texture) const
{
    TPoints2DList uvpointList;
    
    APoint2D t1 = APoint2D(0.0f, 0.0f);
    APoint2D t2 = APoint2D(0.0f, 1.0f);
    APoint2D t3 = APoint2D(1.0f, 1.0f);
    APoint2D t4 = APoint2D(1.0f, 0.0f);

    uvpointList.push_back(t2);
    uvpointList.push_back(t4);
    uvpointList.push_back(t1);

    uvpointList.push_back(t2);
    uvpointList.push_back(t3);
    uvpointList.push_back(t4);

    return uvpointList;
}

//==============================================================================

TPoints2DList AButton::generatePlanePoints(const ASize2D& squarePlaneSize) const
{
    TPoints2DList pointList;
    
    APoint2D p1 = buttonPosition;
    APoint2D p2 = APoint2D(p1.x,                         p1.y + squarePlaneSize.height);
    APoint2D p3 = APoint2D(p1.x + squarePlaneSize.width, p1.y + squarePlaneSize.height);
    APoint2D p4 = APoint2D(p1.x + squarePlaneSize.width, p1.y);
    
    pointList.push_back(p1);
    pointList.push_back(p3);
    pointList.push_back(p2);
    pointList.push_back(p1);
    pointList.push_back(p4);
    pointList.push_back(p3);
    
    return pointList;
}

//==============================================================================

void AButton::renderObject() const
{
    TPoints2DList coordspoints = generatePlanePoints(buttonSize);
    TPoints2DList uvpoints = generatePlaneUVPoints(_texture);
    TFloat line [] = {
        coordspoints[0].x, coordspoints[0].y,
        uvpoints[0].x, uvpoints[0].y,

        coordspoints[1].x, coordspoints[1].y,
        uvpoints[1].x, uvpoints[1].y,

        coordspoints[2].x, coordspoints[2].y,
        uvpoints[2].x, uvpoints[2].y,

        coordspoints[3].x, coordspoints[3].y,
        uvpoints[3].x, uvpoints[3].y,

        coordspoints[4].x, coordspoints[4].y,
        uvpoints[4].x, uvpoints[4].y,

        coordspoints[5].x, coordspoints[5].y,
        uvpoints[5].x, uvpoints[5].y
    };

    
    TUint strideInBytes = sizeof(TFloat) * 4;
    
    _texture.bind();
    AOGLWrapper::oglTexCoordPointer(2, GL_FLOAT, strideInBytes, &line[2]);
    ADrawBasics::drawTriangles(line, strideInBytes, 6);
}

//==============================================================================

void AButton::assignTexture(AOpenGLTexture& texture)
{
    _texture = texture;
}

//==============================================================================

void AButton::processEvent(const APoint2D& point)
{
    if ((point.x < buttonPosition.x) || (point.x > buttonPosition.x + buttonSize.width))
    {
        return;
    }
    
    if ((point.y < buttonPosition.y) || (point.y > buttonPosition.y + buttonSize.height))
    {
        return;
    }

    if (!handler)
    {
        return;
    }
    
    handler->handleTapEvent(point, payLoad);
}

//==============================================================================

}   //  namespace spcTGame
