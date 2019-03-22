#ifndef SPCTGAME_AFORMATIONOPERATIONS_H
#define SPCTGAME_AFORMATIONOPERATIONS_H

//==============================================================================

#include "aformation.h"
#include "amatrix.h"
#include "afrustumborder.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class AFormationOperations
{
private:
    static void defineAxisNewDimension(const TFloat oglCoord, TInt* currentMax, TInt* currentMin);
    static APoint applyMatrixToPoint(const AMatrix& mat, const APoint& in);
    static void frustumBlockPosition(APoint& point, const AFormation* f, const AFrustumBorder& frustum);

public:
    static AFormation* createRotatedFormation(const AFormation& formnationToRotate, const AMatrix& m);
    static AFormation* createRotatedFrustumFormation(const AFormation& formationToRotate, const AMatrix& m, const AFrustumBorder& frustum);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AFORMATIONOPERATIONS_H
