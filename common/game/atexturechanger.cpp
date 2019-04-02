#include "atexturechanger.h"
#include "anodeobject.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

ATextureChanger::ATextureChanger(const spcWAD::ASprite& wadSprite)
{
    _texturesList = AAnimationBuilder().buildAnimation(wadSprite);
}

//==============================================================================

ATextureChanger::~ATextureChanger()
{
}

//==============================================================================

void ATextureChanger::make(ANodeObject *object)  const
{
    printf("texture changers\n");
}

//==============================================================================

}   //  namespace spcTGame
