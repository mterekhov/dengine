#ifndef SPCTGAME_AMONSTER_H
#define SPCTGAME_AMONSTER_H

//==============================================================================

#include "ascenenode.h"
#include "apoint.h"

//==============================================================================

class ATexture;

//==============================================================================

namespace spcTGame
{

//==============================================================================

class AMonster : public ASceneNode
{
private:
    const ATexture& _texture;
    APoint _point;
    
public:
    AMonster(const APoint& point, const ATexture& texture);
    ~AMonster();

    virtual void renderObject();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AMONSTER_H
