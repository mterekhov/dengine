#ifndef SPCTGAME_ATEXTURECHANGER_H
#define SPCTGAME_ATEXTURECHANGER_H

//==============================================================================

#include "achanger.h"
#include "aanimationbuilder.h"
#include "atexturemanager.h"
#include "avector.h"

//==============================================================================

namespace spcTGame
{

struct TSpriteAnimationFrame
{
    AOpenGLTexture texture;
    AVector scale;
};

typedef std::vector<TSpriteAnimationFrame> TProjectionsList;
typedef TProjectionsList::iterator TProjectionsListIter;
typedef TProjectionsList::const_iterator TProjectionsListConstIter;

typedef std::list<TProjectionsList> TFramesList;
typedef TFramesList::iterator TFramesListIter;
typedef TFramesList::const_iterator TFramesListConstIter;


//==============================================================================

class ASpriteChanger : public AChanger
{
private:
    ATextureManager& _textureManager;

    TFramesList _framesList;
    TFramesListIter _framesListIter;

public:
    ASpriteChanger(const spcWAD::ASprite& wadSprite, ATextureManager& textureManager);
    virtual ~ASpriteChanger();
    
    virtual void make(ANodeObject *object);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ATEXTURECHANGER_H
