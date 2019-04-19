#ifndef SPCTGAME_ABANNER_H
#define SPCTGAME_ABANNER_H

//==============================================================================

#include "anodeobject.h"
#include "aopengltexture.h"
#include "apoint2d.h"
#include "asize2d.h"
#include "abuttonhandler.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ABanner : public ANodeObject
{
private:
    AOpenGLTexture _texture;

    TPoints2DList generatePlaneUVPoints(const AOpenGLTexture& texture) const;
    TPoints2DList generatePlanePoints(const ASize2D& squarePlaneSize) const;

public:
    ABanner(AOpenGLTexture& texture);
    virtual ~ABanner();

    virtual void renderObject() const;
    virtual void assignTexture(AOpenGLTexture& texture);

    ASize2D bannerSize;
    APoint2D bannerPosition;
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ABANNER_H
