#include "adrawbasics.h"
#include "aopenglstate.h"
#include "blockoutdebug.h"
#include "aoglwrapper.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
#pragma mark - render basics -

//==============================================================================
    
void ADrawBasics::drawDataLiner(const ADataLiner& dataLiner)
{
    TFloat* line = new TFloat[dataLiner.numberOfFloatValues()];
    memset(line, 0, dataLiner.numberOfFloatValues() * sizeof(TFloat));
    
    if (dataLiner.generateArray(line) == false)
    {
        return;
    }
    
    TUint strideInBytes = sizeof(TFloat) * dataLiner.arrayStride();
    
    AOGLWrapper::oglTexCoordPointer(2, GL_FLOAT, strideInBytes, &line[3]);
    ADrawBasics::drawTriangles(line, strideInBytes, dataLiner.pointsCount());

    delete [] line;

}

//==============================================================================

void ADrawBasics::drawTexturedPlane(const TPointsList& coordspoints, const TPoints2DList uvpoints, const AOpenGLTexture& texture)
{
    ADataLiner dataLiner;
    dataLiner.pushCoordPointList(coordspoints);
    dataLiner.pushUVPointList(uvpoints);
    
    TFloat* line = new TFloat[dataLiner.numberOfFloatValues()];
    memset(line, 0, dataLiner.numberOfFloatValues() * sizeof(TFloat));
    
    if (dataLiner.generateArray(line) == false)
    {
        return;
    }
    
    AOpenGLState *instance = AOpenGLState::shared();
    instance->currentTexture(texture);
    
    TUint strideInBytes = sizeof(TFloat) * dataLiner.arrayStride();
    
    AOGLWrapper::oglTexCoordPointer(2, GL_FLOAT, strideInBytes, &line[3]);
    ADrawBasics::drawTriangles(line, strideInBytes, dataLiner.pointsCount());
    
    instance->clearCurrentTexture();
    
    delete [] line;
}

//==============================================================================
    
void ADrawBasics::drawTexturedCube(const APoint& pos, const TFloat cubeSize, AOpenGLTexture& texture)
{
    TPointsList coordspoints = ADrawBasics::generateCoords(pos, cubeSize);
    TPoints2DList uvpoints = ADrawBasics::generateUV(texture);
    ADataLiner dataLiner;
    dataLiner.pushCoordPointList(coordspoints);
    dataLiner.pushUVPointList(uvpoints);

    TFloat* line = new TFloat[dataLiner.numberOfFloatValues()];
    memset(line, 0, dataLiner.numberOfFloatValues() * sizeof(TFloat));
    
    if (dataLiner.generateArray(line) == false)
    {
        loger("failed to generate array of vertexes");
        return;
    }
    
    AOpenGLState* instance = AOpenGLState::shared();
    instance->currentTexture(texture);

    TUint strideInBytes = sizeof(TFloat) * dataLiner.arrayStride();
    AOGLWrapper::oglTexCoordPointer(2, GL_FLOAT, strideInBytes, &line[3]);
    ADrawBasics::drawTriangles(line, strideInBytes, dataLiner.pointsCount());

    instance->clearCurrentTexture();
    
    delete [] line;
}

//==============================================================================

void ADrawBasics::drawSolidCube(const APoint& location, const TFloat cubeSize)
{
    TPointsList pointsList = ADrawBasics::generateCoords(location, cubeSize);
    ADataLiner dataLiner;
    dataLiner.pushCoordPointList(pointsList);

    ADrawBasics::drawTriangles(dataLiner);
}

//==============================================================================

void ADrawBasics::drawCarcasedCube(const APoint& location, const TFloat cubeSize)
{
    AOpenGLState* oglState = AOpenGLState::shared();
    TFloat oldWidth = oglState->lineWidth();
    oglState->lineWidth(3);
    APoint p1 = location;
    APoint p2 = APoint(location.x + cubeSize, location.y, location.z);
    APoint p3 = APoint(location.x + cubeSize, location.y, location.z + cubeSize);
    APoint p4 = APoint(location.x,            location.y, location.z + cubeSize);

    ADrawBasics::drawLine(p1, p2);
    ADrawBasics::drawLine(p2, p3);
    ADrawBasics::drawLine(p3, p4);
    ADrawBasics::drawLine(p4, p1);

    APoint p5 = APoint(location.x,            location.y + cubeSize, location.z);
    APoint p6 = APoint(location.x + cubeSize, location.y + cubeSize, location.z);
    APoint p7 = APoint(location.x + cubeSize, location.y + cubeSize, location.z + cubeSize);
    APoint p8 = APoint(location.x,            location.y + cubeSize, location.z + cubeSize);

    ADrawBasics::drawLine(p5, p6);
    ADrawBasics::drawLine(p6, p7);
    ADrawBasics::drawLine(p7, p8);
    ADrawBasics::drawLine(p8, p5);

    ADrawBasics::drawLine(p5, p1);
    ADrawBasics::drawLine(p6, p2);
    ADrawBasics::drawLine(p7, p3);
    ADrawBasics::drawLine(p8, p4);

    oglState->lineWidth(oldWidth);
}

//==============================================================================

void ADrawBasics::drawLine(const APoint& p1, const APoint& p2)
{
    TFloat line[6] = {0};
    line[0] = p1.x;
    line[1] = p1.y;
    line[2] = p1.z;

    line[3] = p2.x;
    line[4] = p2.y;
    line[5] = p2.z;

    AOGLWrapper::oglVertexPointer(3, GL_FLOAT, 0, line);
    AOGLWrapper::oglDrawArrays(GL_LINES, 0, 2);
}

//==============================================================================

void ADrawBasics::drawOrigin(const APoint& location, const TFloat scale)
{
    AOpenGLState* oglInstance = AOpenGLState::shared();
    AColor color = oglInstance->drawColor();
    
    oglInstance->drawColor(AColor::redColor());
    APoint tmpPoint = APoint(location.x + scale, location.y, location.z);
    drawLine(location, tmpPoint);
    
    oglInstance->drawColor(AColor::greenColor());
    tmpPoint.x = location.x;
    tmpPoint.y = location.y + scale;
    tmpPoint.z = location.z;
    drawLine(location, tmpPoint);
    
    oglInstance->drawColor(AColor::blueColor());
    tmpPoint.x = location.x;
    tmpPoint.y = location.y;
    tmpPoint.z = location.z + scale;
    drawLine(location, tmpPoint);
    
    oglInstance->drawColor(color);
}

//==============================================================================

void ADrawBasics::drawGrid(const TFloat rowsNumber, const TFloat columnsNumber, const TFloat scale)
{
    AOpenGLState* oglInstance = AOpenGLState::shared();
    AColor color = oglInstance->drawColor();

    oglInstance->drawColor(AColor::whiteColor());
    for (TFloat i = -rowsNumber; i < rowsNumber; i+= 1.0f)
        drawLine(APoint(-rowsNumber * scale, 0.0f, i * scale), APoint(rowsNumber * scale, 0.0f, i * scale));

    for (TFloat i = -columnsNumber; i < columnsNumber; i+= 1.0f)
        drawLine(APoint(i * scale, 0.0f, -columnsNumber * scale), APoint(i * scale, 0.0f, columnsNumber * scale));

    oglInstance->drawColor(color);
}

//==============================================================================

void ADrawBasics::installCamera(const AVector& eyePosition3D, const AVector& center3D, const AVector& upVector3D)
{
    TFloat m[16] = {0.0f};
    TFloat x[3] = {0.0f};
    TFloat y[3] = {0.0f};
    TFloat z[3] = {0.0f};
    TFloat mag = 0.0f;

    /* Make rotation matrix */

    /* Z vector */
    z[0] = eyePosition3D.x - center3D.x;
    z[1] = eyePosition3D.y - center3D.y;
    z[2] = eyePosition3D.z - center3D.z;
    mag = sqrtf(z[0] * z[0] + z[1] * z[1] + z[2] * z[2]);
    if (mag) {          /* mpichler, 19950515 */
        z[0] /= mag;
        z[1] /= mag;
        z[2] /= mag;
    }

    /* Y vector */
    y[0] = upVector3D.x;
    y[1] = upVector3D.y;
    y[2] = upVector3D.z;

    /* X vector = Y cross Z */
    x[0] = y[1] * z[2] - y[2] * z[1];
    x[1] = -y[0] * z[2] + y[2] * z[0];
    x[2] = y[0] * z[1] - y[1] * z[0];

    /* Recompute Y = Z cross X */
    y[0] = z[1] * x[2] - z[2] * x[1];
    y[1] = -z[0] * x[2] + z[2] * x[0];
    y[2] = z[0] * x[1] - z[1] * x[0];

    /* mpichler, 19950515 */
    /* cross product gives area of parallelogram, which is < 1.0 for
     * non-perpendicular unit-length vectors; so normalize x, y here
     */

    mag = sqrtf(x[0] * x[0] + x[1] * x[1] + x[2] * x[2]);
    if (mag) {
        x[0] /= mag;
        x[1] /= mag;
        x[2] /= mag;
    }

    mag = sqrt(y[0] * y[0] + y[1] * y[1] + y[2] * y[2]);
    if (mag) {
        y[0] /= mag;
        y[1] /= mag;
        y[2] /= mag;
    }

    #define M(row,col)  m[col * 4 + row]
    M(0, 0) = x[0];
    M(0, 1) = x[1];
    M(0, 2) = x[2];
    M(0, 3) = 0.0f;
    M(1, 0) = y[0];
    M(1, 1) = y[1];
    M(1, 2) = y[2];
    M(1, 3) = 0.0f;
    M(2, 0) = z[0];
    M(2, 1) = z[1];
    M(2, 2) = z[2];
    M(2, 3) = 0.0f;
    M(3, 0) = 0.0f;
    M(3, 1) = 0.0f;
    M(3, 2) = 0.0f;
    M(3, 3) = 1.0f;
    #undef M
    AOGLWrapper::oglMultMatrixf(m);

    /* Translate Eye to Origin */
    AOGLWrapper::oglTranslatef(-eyePosition3D.x, -eyePosition3D.y, -eyePosition3D.z);
}

//==============================================================================
    
#pragma mark - Routines -

//==============================================================================

void ADrawBasics::drawTriangles(const TFloat* pointsArray, const TUint stride, const TUint pointsCount)
{
    if (!pointsArray)
    {
        loger("failed to draw array of vertexes");
        return;
    }

    AOGLWrapper::oglVertexPointer(3, GL_FLOAT, stride, pointsArray);
    AOGLWrapper::oglDrawArrays(GL_TRIANGLES, 0, pointsCount);
}

//==============================================================================

void ADrawBasics::drawTriangles(const ADataLiner& dataLiner)
{
    TUint numberOfFloatValues = dataLiner.numberOfFloatValues();
    TFloat* line = new TFloat[numberOfFloatValues];
    memset(line, 0, numberOfFloatValues * sizeof(TFloat));
    if (dataLiner.generateArray(line) == false)
    {
        loger("failed to generate array of vertexes");
        return;
    }

    drawTriangles(line, (dataLiner.arrayStride() == 3) ? 0 : dataLiner.arrayStride(), dataLiner.pointsCount());
    
    delete [] line;
}

//==============================================================================


TPoints2DList ADrawBasics::generateUV(const AOpenGLTexture& tex)
{
    TPoints2DList points;
    
    TFloat xaspect = static_cast<TFloat>(tex.imageWidth()) / static_cast<TFloat>(tex.width());
    TFloat yaspect = static_cast<TFloat>(tex.imageHeight()) / static_cast<TFloat>(tex.height());

    APoint2D p1 = APoint2D(0.0f, 0.0f);
    APoint2D p2 = APoint2D(0.0f, yaspect);
    APoint2D p3 = APoint2D(xaspect, yaspect);
    APoint2D p4 = APoint2D(xaspect, 0.0f);

    points.push_back(p3);
    points.push_back(p2);
    points.push_back(p4);
    points.push_back(p2);
    points.push_back(p1);
    points.push_back(p4);

    points.push_back(p2);
    points.push_back(p1);
    points.push_back(p3);
    points.push_back(p3);
    points.push_back(p1);
    points.push_back(p4);
    
    points.push_back(p2);
    points.push_back(p1);
    points.push_back(p3);
    points.push_back(p3);
    points.push_back(p1);
    points.push_back(p4);

    points.push_back(p3);
    points.push_back(p2);
    points.push_back(p4);
    points.push_back(p2);
    points.push_back(p1);
    points.push_back(p4);

    points.push_back(p3);
    points.push_back(p2);
    points.push_back(p4);
    points.push_back(p2);
    points.push_back(p1);
    points.push_back(p4);

    points.push_back(p2);
    points.push_back(p1);
    points.push_back(p3);
    points.push_back(p3);
    points.push_back(p1);
    points.push_back(p4);

    return points;
}

//==============================================================================

TPointsList ADrawBasics::generateCoords(const APoint& location, const TFloat cubeSize)
{
    APoint p2 = APoint(location.x + cubeSize, location.y, location.z);
    APoint p3 = APoint(location.x + cubeSize, location.y, location.z + cubeSize);
    APoint p6 = APoint(location.x + cubeSize, location.y + cubeSize, location.z);
    APoint p7 = APoint(location.x + cubeSize, location.y + cubeSize, location.z + cubeSize);
    
    APoint p1 = location;
    APoint p4 = APoint(location.x,            location.y,            location.z + cubeSize);
    APoint p8 = APoint(location.x,            location.y + cubeSize, location.z + cubeSize);
    APoint p5 = APoint(location.x,            location.y + cubeSize, location.z);

    TPointsList points;
    
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p4);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);

    points.push_back(p5);
    points.push_back(p8);
    points.push_back(p6);
    points.push_back(p6);
    points.push_back(p8);
    points.push_back(p7);
    
    points.push_back(p5);
    points.push_back(p1);
    points.push_back(p8);
    points.push_back(p8);
    points.push_back(p1);
    points.push_back(p4);

    points.push_back(p5);
    points.push_back(p6);
    points.push_back(p1);
    points.push_back(p6);
    points.push_back(p2);
    points.push_back(p1);

    points.push_back(p6);
    points.push_back(p7);
    points.push_back(p2);
    points.push_back(p7);
    points.push_back(p3);
    points.push_back(p2);

    points.push_back(p8);
    points.push_back(p4);
    points.push_back(p7);
    points.push_back(p7);
    points.push_back(p4);
    points.push_back(p3);

    return points;
}

//==============================================================================

}   //  namespace spcTGame
