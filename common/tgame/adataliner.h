#ifndef SPCTGAME_ADATALINER_H
#define SPCTGAME_ADATALINER_H

//==============================================================================

#include "apoint.h"
#include "apoint2d.h"
#include "blockouttypes.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
enum EIntegrity
{
    EINTEGRITY_OK,
    EINTEGRITY_INCONSISTENT
};

//==============================================================================

class ADataLiner
{
private:
    TPointsList _coordsList;
    TPoints2DList _uvList;
    TPointsList _normalsList;

public:
    ADataLiner();
    ~ADataLiner();
    
    void pushPoint(const APoint& coords);
    void pushUVPoint(const APoint2D& point);
    void pushNormalPoint(const APoint& point);

    void pushCoordPointList(const TPointsList& pointsList);
    void pushUVPointList(const TPoints2DList& pointsList);
    void pushNormalPointList(const TPointsList& pointsList);
    
    TUint numberOfFloatValues() const;
    TUint arrayStride() const;
    TUint pointsCount() const;

    EIntegrity checkIntegrity() const;
    TBool generateArray(TFloat* resultArray) const;
    void printData() const;
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ADATALINER_H
