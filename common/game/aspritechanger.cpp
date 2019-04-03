#include "aspritechanger.h"
#include "anodeobject.h"
#include "aopengltexture.h"
#include "aopenglstate.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

ASpriteChanger::ASpriteChanger(const spcWAD::ASprite& wadSprite, ATextureManager& textureManager) : _textureManager(textureManager)
{
    TFramesList animationsList;
    
    //  ABCD is walking
    //  EFGH is striking
    //  IJKLMNO die
    
    TAnimationFramesList picturesList = AAnimationBuilder().buildAnimation(wadSprite);
    TInt maxHeight = wadSprite.spriteHeight();
    TInt maxWidth = wadSprite.spriteWidth();
    for (TAnimationFramesListIter iter = picturesList.begin(); iter != picturesList.end(); iter++)
    {
        TFrameProjectionsList pictureProjectionsList = *iter;
        TProjectionsList textureProjections;
        for (TFrameProjectionsListIter pictureIter = pictureProjectionsList.begin(); pictureIter != pictureProjectionsList.end(); pictureIter++)
        {
            spcWAD::APicture picture = *pictureIter;
            TSpriteAnimationFrame newFrame;
            AOpenGLTexture& frameTexture = _textureManager.createOrFindTexture(picture.patchName(), picture.imageData);
            newFrame.texture = frameTexture;
//            newFrame.scale = AVector(1, static_cast<TFloat>(maxWidth) / static_cast<TFloat>(picture.imageData.width()), static_cast<TFloat>(maxHeight) / static_cast<TFloat>(picture.imageData.height()));
            newFrame.scale = AVector(1,1,0.1);
            textureProjections.push_back(newFrame);
        }
        animationsList.push_back(textureProjections);
    }
    
    _framesList = animationsList;
    _framesListIter = _framesList.begin();
}

//==============================================================================

ASpriteChanger::~ASpriteChanger()
{
}

//==============================================================================

void ASpriteChanger::make(ANodeObject *object)
{
    TProjectionsList projections = *_framesListIter;
    object->applyTexture(projections[0].texture);
    AOpenGLState *instance = AOpenGLState::shared();
    instance->scale(projections[0].scale);

    _framesListIter++;
    if (_framesListIter == _framesList.end())
    {
        _framesListIter = _framesList.begin();
    }
}

//==============================================================================

}   //  namespace spcTGame