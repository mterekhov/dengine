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
        frameName = frameName.erase(0, wadSprite.spritesPrefix.length());;
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
        tmpProjectionList.push_back(picture);
    }

    return list;
}

//==============================================================================
    
std::list<std::string> AAnimationBuilder::shouldbeMirrored(const std::string& pictureName, const std::string& spritePrefix) const
{
    std::list<std::string> mirornamesList;
    
    std::size_t pos = pictureName.find_last_of(spritePrefix);
    std::string frameId = pictureName.substr(pos + 1);

    return mirornamesList;
}
    
//==============================================================================

}   //  namespace spcTGame