#ifndef SPCTGAME_AOPENGLSPRITE_H
#define SPCTGAME_AOPENGLSPRITE_H

//==============================================================================

#include "anodeobject.h"
#include "aopengltexture.h"
#include "apoint2d.h"
#include "asize2d.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class AOpenGLSprite : public ANodeObject
{
private:
    AOpenGLTexture& _texture;
    
    TPoints2DList generatePlaneUVPoints(const AOpenGLTexture& texture) const;
    TPoints2DList generatePlanePoints(const ASize2D& squarePlaneSize) const;

public:
    AOpenGLSprite(AOpenGLTexture& texture);
    virtual ~AOpenGLSprite();

    virtual void renderObject() const;
    virtual void bindTexture();
    virtual void assignTexture(AOpenGLTexture& texture);

    ASize2D planeSize;
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AOPENGLSPRITE_H
