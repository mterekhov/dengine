#include "amonster.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

AMonster::AMonster(const APoint& point, const ATexture& texture) : _texture(texture), _point(point)
{
    _nodeType = NODETYPE_TEXTURED;
}

//==============================================================================

AMonster::~AMonster()
{
}

//==============================================================================

void AMonster::renderObject()
{
    
}

//==============================================================================

}   //  namespace spcTGame
