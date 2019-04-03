#include "amonster.h"
#include "adrawbasics.h"
#include "aopenglstate.h"
#include "aoglwrapper.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

AMonster::AMonster(AOpenGLTexture& texture) : _texture(texture)
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
//    if (textureWidth >= textureHeight)
//    {
//        monsterWidth = textureHeight / textureWidth;
//    }
//    else
//    {
//        monsterHeight = textureWidth / textureHeight;
//    }
    
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

void AMonster::renderObject() const
{
    TPointsList coordspoints = generatePlanePoints(_texture.imageWidth(), _texture.imageHeight());
    TPoints2DList uvpoints = _texture.generatePlaneUVPoints();
    
    ADataLiner dataLiner;
    dataLiner.pushCoordPointList(coordspoints);
    dataLiner.pushUVPointList(uvpoints);
//    AOpenGLState *instance = AOpenGLState::shared();
//    instance->scale(AVector(1, 1, 0.1));
    ADrawBasics::drawDataLiner(dataLiner);
}

//==============================================================================

void AMonster::applyTexture(AOpenGLTexture& texture)
{
    _texture = texture;
}

//==============================================================================

void AMonster::applyTexture()
{
    _texture.bind();
}

//==============================================================================

}   //  namespace spcTGame
