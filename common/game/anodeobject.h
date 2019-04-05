#ifndef SPCTGAME_ANODEOBJECT
#define SPCTGAME_ANODEOBJECT

//==============================================================================

#include "blockouttypes.h"
#include "aopengltexture.h"
#include "apoint.h"
#include "avector.h"
#include "aquaternion.h"

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
    virtual void assignTexture(AOpenGLTexture& texture);
    virtual void bindTexture();
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ANODEOBJECT

