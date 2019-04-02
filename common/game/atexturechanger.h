#ifndef SPCTGAME_ATEXTURECHANGER_H
#define SPCTGAME_ATEXTURECHANGER_H

//==============================================================================

#include "achanger.h"
#include "aanimationbuilder.h"
#include "atexturemanager.h"

//==============================================================================

namespace spcTGame
{

typedef std::vector<AOpenGLTexture> TProjectionsList;
typedef TProjectionsList::iterator TProjectionsListIter;
typedef TProjectionsList::const_iterator TProjectionsListConstIter;

typedef std::list<TProjectionsList> TFramesList;
typedef TFramesList::iterator TFramesListIter;
typedef TFramesList::const_iterator TFramesListConstIter;


//==============================================================================

class ATextureChanger : public AChanger
{
private:
    ATextureManager& _textureManager;

    TFramesList _framesList;
    TFramesListIter _framesListIter;
public:
    ATextureChanger(const spcWAD::ASprite& wadSprite, ATextureManager& textureManager);
    virtual ~ATextureChanger();
    
    virtual void make(ANodeObject *object);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ATEXTURECHANGER_H
