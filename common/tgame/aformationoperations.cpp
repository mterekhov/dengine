#include <list>

#include "aformationoperations.h"
#include "aformationfactory.h"
#include "blockoutdebug.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

typedef std::list<APoint> TRotatedPoints;
typedef TRotatedPoints::iterator TRPIter;

#define SHIFT_DIMMENSION 3

struct SRotationMetaData
{
    TInt negativeShifts[SHIFT_DIMMENSION];
    TInt newDimmension[SHIFT_DIMMENSION];
    
    TRotatedPoints rotatedPoints;
};

//==============================================================================

AFormation* AFormationOperations::createRotatedFrustumFormation(const AFormation& formationToRotate, const AMatrix& m, const AFrustumBorder& frustum)
{
    APoint gridPoint = formationToRotate.gridSpacePosition();
    
    AFormation* rotatedFormation = createRotatedFormation(formationToRotate, m);
    frustumBlockPosition(gridPoint, rotatedFormation, frustum);
    rotatedFormation->gridSpacePosition(gridPoint);
    
    return rotatedFormation;
}

//==============================================================================

AFormation* AFormationOperations::createRotatedFormation(const AFormation& formationToRotate, const AMatrix& m)
{
    TInt maxWidth = 0;
    TInt maxHeight = 0;
    TInt maxLevels = 0;
    TInt minWidth = 0;
    TInt minHeight = 0;
    TInt minLevels = 0;
    
    SRotationMetaData rotationMeta;
    for (TInt l = 0; l < formationToRotate.levelsCount(); l++)
    {
        for (TInt i = 0; i < formationToRotate.height(); i++)
        {
            for (TInt j = 0; j < formationToRotate.width(); j++)
            {
                TData value = formationToRotate.item(j, i, l);
                if (value == EDATASTATE_RENDERABLE)
                {
                    APoint pointToRotate(i, l, j);
                    APoint rotated = applyMatrixToPoint(m, pointToRotate);
                    rotationMeta.rotatedPoints.push_back(rotated);
                    
                    defineAxisNewDimension(rotated.z, &maxWidth, &minWidth);
                    defineAxisNewDimension(rotated.x, &maxHeight, &minHeight);
                    defineAxisNewDimension(rotated.y, &maxLevels, &minLevels);
                }
            }
        }
    }

    rotationMeta.newDimmension[0] = maxWidth - minWidth + 1;
    rotationMeta.newDimmension[1] = maxHeight - minHeight + 1;
    rotationMeta.newDimmension[2] = maxLevels - minLevels + 1;
    rotationMeta.negativeShifts[2] = std::abs(minWidth);
    rotationMeta.negativeShifts[0] = std::abs(minHeight);
    rotationMeta.negativeShifts[1] = std::abs(minLevels);

    AFormation* rotatedFormation = AFormationFactory::createFormation(rotationMeta.newDimmension[0], rotationMeta.newDimmension[1], rotationMeta.newDimmension[2]);
    for (TRPIter iter = rotationMeta.rotatedPoints.begin(); iter != rotationMeta.rotatedPoints.end(); iter++)
    {
        APoint p = *iter;
        p.x += rotationMeta.negativeShifts[0];
        p.y += rotationMeta.negativeShifts[1];
        p.z += rotationMeta.negativeShifts[2];
        TInt column = static_cast<TUint>(round(p.z));
        TInt row = static_cast<TUint>(round(p.x));
        TInt level = static_cast<TUint>(round(p.y));
        
        TBool r = rotatedFormation->item(column, row, level, EDATASTATE_RENDERABLE);
        if (r == false)
        {
            loger("can not rotate");
        }
    }
    
    return rotatedFormation;
}

//==============================================================================

void AFormationOperations::frustumBlockPosition(APoint& point, const AFormation* f, const AFrustumBorder& frustum)
{
    TFloat shift = static_cast<TFloat>(f->height()) + point.x;
    if (shift > frustum.x)
        point.x += frustum.x - shift;
    
    shift = static_cast<TFloat>(f->width()) + point.z;
    if (shift > frustum.z)
        point.z += frustum.z - shift;
    
    shift = static_cast<TFloat>(f->levelsCount()) + point.y;
    if (shift > frustum.y)
        point.y += frustum.y - shift;
}

//==============================================================================

void AFormationOperations::defineAxisNewDimension(const TFloat oglCoord, TInt* currentMax, TInt* currentMin)
{
    TFloat min = static_cast<TFloat>(*currentMin);
    TFloat max = static_cast<TFloat>(*currentMax);
    if (oglCoord < min)
    {
        min = oglCoord;
    }
    
    if (oglCoord > max)
    {
        max = oglCoord;
    }

    *currentMin = static_cast<TInt>(roundf(min));
    *currentMax = static_cast<TInt>(roundf(max));
}

//==============================================================================

APoint AFormationOperations::applyMatrixToPoint(const AMatrix& mat, const APoint& in)
{
    APoint res;
    res.x = mat.m[0][0] * in.x + mat.m[1][0] * in.y + mat.m[2][0] * in.z + mat.m[3][0];
    res.y = mat.m[0][1] * in.x + mat.m[1][1] * in.y + mat.m[2][1] * in.z + mat.m[3][1];
    res.z = mat.m[0][2] * in.x + mat.m[1][2] * in.y + mat.m[2][2] * in.z + mat.m[3][2];
    TFloat out3 = mat.m[0][3] * in.x + mat.m[1][3] * in.y + mat.m[2][3] * in.z + mat.m[3][3];
    
    res.x /= out3;
    res.y /= out3;
    res.z /= out3;
    
    return res;
}

//==============================================================================

}   //  namespace spcTGame
