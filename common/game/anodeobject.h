#ifndef SPCTGAME_ANODEOBJECT
#define SPCTGAME_ANODEOBJECT

//==============================================================================

#include "blockouttypes.h"
#include "aopengltexture.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

class ANodeObject
{
public:
    ANodeObject();
    virtual ~ANodeObject();
    
    virtual void renderObject() const;
    virtual void applyTexture(AOpenGLTexture& texture);
    virtual void applyTexture();
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ANODEOBJECT

