#ifndef SPCTGAME_APLANE_H
#define SPCTGAME_APLANE_H

//==============================================================================

#include "anodeobject.h"
#include "atexture.h"
#include "apoint2d.h"
#include "apoint.h"

//==============================================================================

class ATexture;
class TPoints2DList;

//==============================================================================

namespace spcTGame
{

//==============================================================================

class APlane : public ANodeObject
{
private:
    const ATexture& _texture;
    
    TPoints2DList generatePlaneUVPoints(const ATexture& texture) const;
    TPointsList generatePlanePoints(const TFloat squarePlaneSize) const;

public:
    APlane(ATexture& texture);
    virtual ~APlane();

    virtual void renderObject() const;
    
    TFloat planeSize;
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_APLANE_H
