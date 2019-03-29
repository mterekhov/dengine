#ifndef SPCTGAME_AMONSTER_H
#define SPCTGAME_AMONSTER_H

//==============================================================================

#include "anodeobject.h"
#include "atexture.h"
#include "apoint2d.h"
#include "apoint.h"

//==============================================================================

class ATexture;
class TPoints2DList;

//==============================================================================

namespace spcTGame
{

//==============================================================================

class AMonster : public ANodeObject
{
private:
    const ATexture& _texture;
    
    TPoints2DList generatePlaneUVPoints(const ATexture& texture) const;
    TPointsList generatePlanePoints(const TFloat textureWidth, const TFloat textureHeight) const;

public:
    AMonster(ATexture& texture);
    virtual ~AMonster();

    virtual void renderObject() const;
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AMONSTER_H
