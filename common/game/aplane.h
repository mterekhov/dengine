#ifndef SPCTGAME_APLANE_H
#define SPCTGAME_APLANE_H

//==============================================================================

#include "anodeobject.h"
#include "aopengltexture.h"
#include "apoint2d.h"
#include "apoint.h"

//==============================================================================

class TPoints2DList;

//==============================================================================

namespace spcTGame
{

//==============================================================================

class APlane : public ANodeObject
{
private:
    AOpenGLTexture _texture;
    
    TPoints2DList generatePlaneUVPoints(const AOpenGLTexture& texture) const;
    TPointsList generatePlanePoints(const TFloat squarePlaneSize) const;

public:
    APlane(AOpenGLTexture& texture);
    virtual ~APlane();

    virtual void renderObject() const;
    virtual void bindTexture();
    virtual void assignTexture(AOpenGLTexture& texture);

    TFloat planeSize;
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_APLANE_H
