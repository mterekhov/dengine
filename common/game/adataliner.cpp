#include "adataliner.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
ADataLiner::ADataLiner()
{
}

//==============================================================================

ADataLiner::~ADataLiner()
{
}

//==============================================================================

EIntegrity ADataLiner::checkIntegrity() const
{
    EIntegrity result = EINTEGRITY_OK;
    
    TUint coordsSize = static_cast<TUint>(_coordsList.size());
    if (!coordsSize)
        return EINTEGRITY_OK;
    
    TUint uvSize = static_cast<TUint>(_uvList.size());
    if (uvSize)
        if (coordsSize != uvSize)
            return EINTEGRITY_INCONSISTENT;
    
    TUint normalsSize = static_cast<TUint>(_normalsList.size());
    if (normalsSize)
        if (coordsSize != normalsSize)
            return EINTEGRITY_INCONSISTENT;

    return result;
}

//==============================================================================

TUint ADataLiner::pointsCount() const
{
    return static_cast<TUint>(_coordsList.size());
}

//==============================================================================

TUint ADataLiner::numberOfFloatValues() const
{
    return arrayStride() * pointsCount();
}

//==============================================================================

TUint ADataLiner::arrayStride() const
{
    if (checkIntegrity() != EINTEGRITY_OK)
        return 0;

    TUint result = 0;

    if (!_coordsList.size())
        return 0;
    result += 3;

    if (_uvList.size())
        result += 2;

    if (_normalsList.size())
        result += 3;

    return result;
}

//==============================================================================

TBool ADataLiner::generateArray(TFloat* resultArray) const
{
    if (!resultArray)
        return false;

    if (checkIntegrity() != EINTEGRITY_OK)
        return false;
    
    TUint stride = arrayStride();
    TUint sizer = numberOfFloatValues();
    if (!sizer)
        return false;
    
    memset(resultArray, 0, sizer * sizeof(TFloat));
    
    for (TUint i = 0; i < _coordsList.size(); i++)
    {
        APoint point = _coordsList[i];
        resultArray[stride * i] = point.x;
        resultArray[stride * i + 1] = point.y;
        resultArray[stride * i + 2] = point.z;

        if (_uvList.size())
        {
            APoint2D point2d = _uvList[i];
            resultArray[stride * i + 3] = point2d.x;
            resultArray[stride * i + 4] = point2d.y;
        }
        
        if (_normalsList.size())
        {
            point = _normalsList[i];
            resultArray[stride * i + 5] = point.x;
            resultArray[stride * i + 6] = point.y;
            resultArray[stride * i + 7] = point.z;
        }
    }
    
    return true;
}

//==============================================================================

void ADataLiner::printData() const
{
    for (TUint i = 0; i < _coordsList.size(); i++)
    {
        printf("%i. xyz: %.3f\t%.3f\t%.3f\t\t", i, _coordsList[i].x, _coordsList[i].y, _coordsList[i].z);
        if (_uvList.size())
            printf("uv: %.3f\t%.3f\t\t", _uvList[i].x, _uvList[i].y);

        if (_normalsList.size())
            printf("normals: %.3f\t%.3f\t%.3f", _normalsList[i].x, _normalsList[i].y, _normalsList[i].z);
        
        printf("\n");
    }
}

//==============================================================================
    
#pragma mark - pushers -

//==============================================================================

void ADataLiner::pushPoint(const APoint& coords)
{
    _coordsList.push_back(coords);
}

//==============================================================================

void ADataLiner::pushUVPoint(const APoint2D& point)
{
    _uvList.push_back(point);
}

//==============================================================================

void ADataLiner::pushNormalPoint(const APoint& point)
{
    _normalsList.push_back(point);
}

//==============================================================================

void ADataLiner::pushCoordPointList(const TPointsList& pointsList)
{
    _coordsList.insert(_coordsList.end(), pointsList.begin(), pointsList.end());
}

//==============================================================================

void ADataLiner::pushUVPointList(const TPoints2DList& pointsList)
{
    _uvList.insert(_uvList.end(), pointsList.begin(), pointsList.end());
}

//==============================================================================

void ADataLiner::pushNormalPointList(const TPointsList& pointsList)
{
    _normalsList.insert(_normalsList.end(), pointsList.begin(), pointsList.end());
}

//==============================================================================

}   //  namespace spcTGame
