#include "abanner.h"
#include "adrawbasics.h"
#include "aopenglstate.h"
#include "aoglwrapper.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

ABanner::ABanner(AOpenGLTexture& texture) : _texture(texture), bannerSize(0.0f, 0.0f), bannerPosition(0.0f, 0.0f)
{
}

//==============================================================================

ABanner::~ABanner()
{
}

//==============================================================================
    
TPoints2DList ABanner::generatePlaneUVPoints(const AOpenGLTexture& texture) const
{
    TPoints2DList uvpointList;
    
    TFloat widthAspect = 1;//roundf(bannerSize.width / texture.imageWidth());
    TFloat heightAspect = 1;//roundf(bannerSize.height / texture.imageHeight());
    APoint2D t1 = APoint2D(0.0f, 0.0f);
    APoint2D t2 = APoint2D(0.0f, heightAspect);
    APoint2D t3 = APoint2D(widthAspect, heightAspect);
    APoint2D t4 = APoint2D(widthAspect, 0.0f);

    uvpointList.push_back(t2);
    uvpointList.push_back(t4);
    uvpointList.push_back(t1);

    uvpointList.push_back(t2);
    uvpointList.push_back(t3);
    uvpointList.push_back(t4);

    return uvpointList;
}

//==============================================================================

TPoints2DList ABanner::generatePlanePoints(const ASize2D& squarePlaneSize) const
{
    TPoints2DList pointList;
    
    APoint2D p1 = bannerPosition;
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

void ABanner::renderObject() const
{
    TPoints2DList coordspoints = generatePlanePoints(bannerSize);
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

void ABanner::assignTexture(AOpenGLTexture& texture)
{
    _texture = texture;
}

//==============================================================================

}   //  namespace spcTGame
