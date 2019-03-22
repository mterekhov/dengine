#include "acoloredblock.h"
#include "adrawbasics.h"
#include "aopenglstate.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
AColoredBlock::AColoredBlock(AFormation* data) : ABlock(data), _color(AColor::redColor())
{
}

//==============================================================================

AColoredBlock::AColoredBlock(const AColoredBlock& block) : ABlock(block), _color(block._color)
{
}

//==============================================================================

AColoredBlock::~AColoredBlock()
{
}

//==============================================================================

void AColoredBlock::renderObject()
{
    AOpenGLState* oglInstance = AOpenGLState::shared();
    AColor color = oglInstance->drawColor();
    oglInstance->drawColor(_color);

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
                    ADrawBasics::drawCarcasedCube(point, _size);
                }
            }
        }
    }
    oglInstance->drawColor(color);
}

//==============================================================================

AColor AColoredBlock::color() const
{
    return _color;
}

//==============================================================================

void AColoredBlock::color(const AColor& color)
{
    _color = color;
}

//==============================================================================
    
}   //  namespace spcTGame
