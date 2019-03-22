#include <stdio.h>

#include "awell.h"
#include "adrawbasics.h"
#include "aopenglstate.h"
#include "adatastorage.h"
#include "blockoutdebug.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
AWell::AWell(AFormation* content) : ABlock(content)
{
}

//==============================================================================

AWell::~AWell()
{
}

//==============================================================================

void AWell::renderHull() const
{
    AOpenGLState* oglInstance = AOpenGLState::shared();
    
    AColor color = oglInstance->drawColor();
    
    oglInstance->drawColor(AColor::greenColor());
    for (TFloat i = 0.0f; i < _data->width() + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(0.0f, 0.0f, i * _size), APoint(_data->height() * _size, 0.0f, i * _size));

    for (TFloat i = 0.0f; i < _data->height() + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(i * _size, 0.0f, 0.0f), APoint(i * _size, 0.0f, _data->width() * _size));

////////////////////////////////////////////////////////////////////////////////

    for (TFloat i = 0.0f; i < _data->levelsCount() + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(0.0f, i * _size, 0.0f), APoint(_data->height() * _size, i * _size, 0.0f));

    for (TFloat i = 0.0f; i < _data->height() + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(i * _size, 0.0f, 0.0f), APoint(i * _size, _data->levelsCount() * _size, 0.0f));

////////////////////////////////////////////////////////////////////////////////

    for (TFloat i = 0.0f; i < _data->levelsCount() + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(0.0f, i * _size, _data->width() * _size), APoint(_data->height() * _size, i * _size, _data->width() * _size));

    for (TFloat i = 0.0f; i < _data->height() + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(i * _size, 0.0f, _data->width() * _size), APoint(i * _size, _data->levelsCount() * _size, _data->width() * _size));

////////////////////////////////////////////////////////////////////////////////

    for (TFloat i = 0.0f; i < _data->levelsCount() + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(0.0f, i * _size, 0.0f), APoint(0.0f, i * _size, _data->width() * _size));

    for (TFloat i = 0.0f; i < _data->width() + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(0.0f, 0.0f, i * _size), APoint(0.0f, _data->levelsCount() * _size, i * _size));

////////////////////////////////////////////////////////////////////////////////

    for (TFloat i = 0.0f; i < _data->levelsCount() + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(_data->height() * _size, i * _size, 0.0f), APoint(_data->height() * _size, i * _size, _data->width() * _size));

    for (TFloat i = 0.0f; i < _data->width() + 1.0f; i += 1.0f)
        ADrawBasics::drawLine(APoint(_data->height() * _size, 0.0f, i * _size), APoint(_data->height() * _size, _data->levelsCount() * _size, i * _size));

    oglInstance->drawColor(color);
}

//==============================================================================

void AWell::renderObject()
{
    renderHull();
}

//==============================================================================
    
}   //  namespace spcTGame
