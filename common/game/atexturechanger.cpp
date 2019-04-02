#include "atexturechanger.h"
#include "anodeobject.h"
#include "aopengltexture.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

ATextureChanger::ATextureChanger(const spcWAD::ASprite& wadSprite, ATextureManager& textureManager) : _textureManager(textureManager)
{
    TAnimationFramesList framesList = AAnimationBuilder().buildAnimation(wadSprite);
    TAnimationFramesListIter iter = framesList.begin();
    _texturesList = *iter;
    
    _texturesIter = 0;
}

//==============================================================================

ATextureChanger::~ATextureChanger()
{
}

//==============================================================================

void ATextureChanger::make(ANodeObject *object)
{
    const spcWAD::APicture& pic = _texturesList[_texturesIter];
    AOpenGLTexture& newTexture = _textureManager.createOrFindTexture(pic.patchName(), pic.imageData);
    object->applyTexture(newTexture);
    _texturesIter++;
    if (_texturesIter >= _texturesList.size())
    {
        _texturesIter = 0;
    }
}

//==============================================================================

}   //  namespace spcTGame
