#ifndef SPCTGAME_ABLOCK_H
#define SPCTGAME_ABLOCK_H

//==============================================================================

#include "arobject.h"
#include "aformation.h"
#include "acolor.h"
#include "apoint.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
class ABlock : public ARObject
{
protected:
    AFormation* _data;
    TFloat _size;

public:
    ABlock(AFormation* data);
    ABlock(const ABlock& block);
    virtual ~ABlock();
    
    AFormation* data() const;

    TFloat size() const;
};

//==============================================================================

}   //  namespace spcTGame
    
//==============================================================================
    
#endif  //  SPCTGAME_ABLOCK_H
