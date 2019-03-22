#include "atexturedblock.h"
#include "aopenglstate.h"
#include "adrawbasics.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
ATexturedBlock::ATexturedBlock(AFormation* data, const ATexture& tex) : ABlock(data), _texture(tex)
{
    _objectType = OBJECTTYPE_TEXTURED;
}

//==============================================================================

ATexturedBlock::ATexturedBlock(const ATexturedBlock& block) : ABlock(block), _texture(block._texture)
{
}

//==============================================================================

ATexturedBlock::~ATexturedBlock()
{
}

//==============================================================================

void ATexturedBlock::renderObject()
{
    for (TInt l = 0; l < _data->levelsCount(); l++)
    {
        for (TInt i = 0; i < _data->height(); i++)
        {
            for (TInt j = 0; j < _data->width(); j++)
            {
                TData value = _data->item(j, i, l);
                if (value == EDATASTATE_RENDERABLE)
                {
                    APoint point = _data->gridSpaceLocation(i, l, j);
                    ADrawBasics::drawTexturedCube(point, _size, _texture);
                }
            }
        }
    }
}

//==============================================================================
    
}   //  namespace spcTGame
