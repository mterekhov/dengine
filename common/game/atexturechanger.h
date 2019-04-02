#ifndef SPCTGAME_ATEXTURECHANGER_H
#define SPCTGAME_ATEXTURECHANGER_H

//==============================================================================

#include "achanger.h"
#include "aanimationbuilder.h"
#include "atexturemanager.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ATextureChanger : public AChanger
{
private:
    ATextureManager& _textureManager;
    TFrameProjectionsList _texturesList;
    TInt _texturesIter;
public:
    ATextureChanger(const spcWAD::ASprite& wadSprite, ATextureManager& textureManager);
    virtual ~ATextureChanger();
    
    virtual void make(ANodeObject *object);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ATEXTURECHANGER_H
