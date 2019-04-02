#ifndef SPCTGAME_ATEXTURECHANGER_H
#define SPCTGAME_ATEXTURECHANGER_H

//==============================================================================

#include "achanger.h"
#include "aanimationbuilder.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ATextureChanger : public AChanger
{
private:
    TAnimationFramesList _texturesList;
    
public:
    ATextureChanger(const spcWAD::ASprite& wadSprite);
    virtual ~ATextureChanger();
    
    virtual void make(ANodeObject *object) const;
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ATEXTURECHANGER_H
