#ifndef SPCTGAME_AMONSTER_H
#define SPCTGAME_AMONSTER_H

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

class AMonster : public ANodeObject
{
private:
    AOpenGLTexture& _texture;
    
    TPoints2DList generatePlaneUVPoints(const AOpenGLTexture& texture) const;
    TPointsList generatePlanePoints(const TFloat textureWidth, const TFloat textureHeight) const;

public:
    AMonster(AOpenGLTexture& texture);
    virtual ~AMonster();

    virtual void renderObject() const;
    virtual void applyTexture(AOpenGLTexture& texture);
    virtual void applyTexture();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AMONSTER_H
