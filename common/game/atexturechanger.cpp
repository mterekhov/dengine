#include "atexturechanger.h"
#include "anodeobject.h"
#include "aopengltexture.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

ATextureChanger::ATextureChanger(const spcWAD::ASprite& wadSprite, ATextureManager& textureManager) : _textureManager(textureManager)
{
    TFramesList animationsList;
    
    TAnimationFramesList picturesList = AAnimationBuilder().buildAnimation(wadSprite);
    for (TAnimationFramesListIter iter = picturesList.begin(); iter != picturesList.end(); iter++)
    {
        TFrameProjectionsList pictureProjectionsList = *iter;
        TProjectionsList textureProjections;
        for (TFrameProjectionsListIter pictureIter = pictureProjectionsList.begin(); pictureIter != pictureProjectionsList.end(); pictureIter++)
        {
            spcWAD::APicture picture = *pictureIter;
            AOpenGLTexture& newTexture = _textureManager.createOrFindTexture(picture.patchName(), picture.imageData);
            textureProjections.push_back(newTexture);
        }
        animationsList.push_back(textureProjections);
    }
    
    _framesList = animationsList;
    _framesListIter = _framesList.begin();
}

//==============================================================================

//TAnimatedTexturesList ATextureManager::recreateSkippedProjections(TFrameProjectionsList& projectionsList)
//{
//
//}

//==============================================================================

ATextureChanger::~ATextureChanger()
{
}

//==============================================================================

void ATextureChanger::make(ANodeObject *object)
{
    TProjectionsList projections = *_framesListIter;
    AOpenGLTexture& newTexture = projections[0];
    object->applyTexture(newTexture);
    _framesListIter++;
    if (_framesListIter == _framesList.end())
    {
        _framesListIter = _framesList.begin();
    }
}

//==============================================================================

}   //  namespace spcTGame
