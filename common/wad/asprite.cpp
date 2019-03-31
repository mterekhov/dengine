#include <string>

#include "asprite.h"
#include "apalete.h"
#include "autilities.h"

//=============================================================================

namespace spcWAD
{

//=============================================================================

ASprite::ASprite(const std::string& prefix) : spritesPrefix(prefix)
{
}

//=============================================================================

ASprite::ASprite(const ASprite& sprite) : _picturesList(sprite._picturesList), spritesPrefix(sprite.spritesPrefix)
{

}

//=============================================================================

ASprite::~ASprite()
{
}

//=============================================================================

bool ASprite::operator ==(const ASprite & obj) const
{
    if (AUtilities::stringCompare(spritesPrefix, obj.spritesPrefix))
    {
        return true;
    }
    
    return false;
}

//=============================================================================

ASprite& ASprite::operator=(const ASprite& rv)
{
	if (this == &rv)
	{
		return *this;
	}

	spritesPrefix = rv.spritesPrefix;
	_picturesList = rv._picturesList;

	return *this;
}

//=============================================================================

void ASprite::addPicture(const APicture& newPicture)
{
    _picturesList.push_back(newPicture);
}

//=============================================================================

const TPicturesList& ASprite::picturesList() const
{
    return _picturesList;
}

//=============================================================================

const APicture& ASprite::findPicture(const std::string& pictureName) const
{
    for (TPicturesListConstIter iter = _picturesList.begin(); iter != _picturesList.end(); iter++)
    {
        if (AUtilities::stringCompare(iter->patchName(), pictureName))
        {
            return *iter;
        }
    }
    
    return *_picturesList.end();
}

//=============================================================================

};  //  namespace spcWAD
