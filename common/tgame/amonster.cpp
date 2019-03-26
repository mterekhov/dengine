#include "amonster.h"
#include "adrawbasics.h"
#include "aopenglstate.h"
#include "aoglwrapper.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

AMonster::AMonster(const APoint& point, const ATexture& texture) : _texture(texture), _point(point)
{
    _nodeType = NODETYPE_TEXTURED;
}

//==============================================================================

AMonster::~AMonster()
{
}

//==============================================================================

void AMonster::renderObject()
{
//    TPointsList coordspoints = ADrawBasics::generateCoords(_point, cubeSize);
//    TPoints2DList uvpoints = ADrawBasics::generateUV(_texture);
//    ADataLiner dataLiner;
//    dataLiner.pushCoordPointList(coordspoints);
//    dataLiner.pushUVPointList(uvpoints);
//    
//    TFloat* line = new TFloat[dataLiner.numberOfFloatValues()];
//    memset(line, 0, dataLiner.numberOfFloatValues() * sizeof(TFloat));
//    
//    if (dataLiner.generateArray(line) == false)
//    {
//        return;
//    }
//    
//    AOpenGLState *instance = AOpenGLState::shared();
//    instance->currentTexture(_texture);
//    
//    TUint strideInBytes = sizeof(TFloat) * dataLiner.arrayStride();
//    AOGLWrapper::oglTexCoordPointer(2, GL_FLOAT, strideInBytes, &line[3]);
//    ADrawBasics::drawTriangles(line, strideInBytes, dataLiner.pointsCount());
//    
//    instance->clearCurrentTexture();
//    
//    delete [] line;
}

//==============================================================================

}   //  namespace spcTGame
