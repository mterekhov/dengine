#include "aanimationbuilder.h"
#include "autilities.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

AAnimationBuilder::AAnimationBuilder()
{
}

//==============================================================================

AAnimationBuilder::~AAnimationBuilder()
{
}

//==============================================================================

TAnimationFramesList AAnimationBuilder::buildAnimation(const spcWAD::ASprite& wadSprite) const
{
    TAnimationFramesList list;
    TFrameProjectionsList tmpProjectionList;
    const spcWAD::TPicturesList& picturesList = wadSprite.picturesList();
    std::string currentAnimation;
    for (spcWAD::TPicturesListConstIter iter = picturesList.begin(); iter != picturesList.end(); iter++)
    {
        const spcWAD::APicture& picture = *iter;
        std::string frameName = picture.patchName();
        frameName = frameName.erase(0, wadSprite.spritesPrefix.length());
        std::string animationName = frameName.substr(0, 1);
        std::string animationProjection = frameName.substr(1, 1);
        if (!currentAnimation.length())
        {
            currentAnimation = animationName;
        }
        if (!spcWAD::AUtilities::stringCompare(currentAnimation, animationName))
        {
            currentAnimation = animationName;
            if (tmpProjectionList.size())
            {
                list.push_back(tmpProjectionList);
            }
            tmpProjectionList = TFrameProjectionsList();
        }
        TFrameProjectionsList mirrored = shouldbeMirrored(picture, frameName, wadSprite.spritesPrefix);
        tmpProjectionList.insert(tmpProjectionList.end(), mirrored.begin(), mirrored.end());
    }

    return list;
}

//==============================================================================
    
TFrameProjectionsList AAnimationBuilder::shouldbeMirrored(const spcWAD::APicture& picture, const std::string& pictureName, const std::string& spritePrefix) const
{
    TFrameProjectionsList list;
    
    if (pictureName.size() < 3)
    {
        list.push_back(picture);
        return list;
    }
    std::string originalProjection = spritePrefix + pictureName.substr(0, 2);
    std::string mirroredProjection = spritePrefix + pictureName.substr(2, 2);

    spcWAD::APicture original(picture.imageData, originalProjection);
    spcWAD::APicture mirrored(picture.imageData.mirrorImage(), mirroredProjection);
    list.push_back(original);
    list.push_back(mirrored);

    return list;
}
    
//==============================================================================

}   //  namespace spcTGame
