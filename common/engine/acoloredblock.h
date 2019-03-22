#ifndef SPCTGAME_ACOLOREDBLOCK_H
#define SPCTGAME_ACOLOREDBLOCK_H

//==============================================================================

#include "ablock.h"
#include "aformation.h"
#include "acolor.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
class AColoredBlock : public ABlock
{
protected:
    AColor _color;

public:
    AColoredBlock(AFormation* data);
    AColoredBlock(const AColoredBlock& block);
    virtual ~AColoredBlock();
    
    virtual void renderObject();
    
    AColor color() const;
    void color(const AColor& color);
};

//==============================================================================

}   //  namespace spcTGame
    
//==============================================================================
    
#endif  //  SPCTGAME_ACOLOREDBLOCK_H
