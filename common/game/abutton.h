#ifndef SPCTGAME_ABUTTON_H
#define SPCTGAME_ABUTTON_H

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

class AButton : public ANodeObject
{
private:
    AOpenGLTexture& _texture;
    
    TPoints2DList generatePlaneUVPoints(const AOpenGLTexture& texture) const;
    TPoints2DList generatePlanePoints(const ASize2D& squarePlaneSize) const;

public:
    AButton(AOpenGLTexture& texture);
    virtual ~AButton();

    virtual void renderObject() const;
    virtual void bindTexture();
    virtual void assignTexture(AOpenGLTexture& texture);
    
    void processEvent(const APoint2D& point);

    ASize2D buttonSize;
    APoint2D buttonPosition;
    AButtonHandler *handler;
    void *payLoad;
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ABUTTON_H
