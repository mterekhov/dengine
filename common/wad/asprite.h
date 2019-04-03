#ifndef SPCWAD_ASPRITE_H
#define SPCWAD_ASPRITE_H

//=============================================================================

#include <string>

#include "apicture.h"
#include "types.h"

//=============================================================================

class APalete;

//=============================================================================

namespace spcWAD
{

//=============================================================================

/**
 Sprite is the image of thing. Not every thing has Sprite. Every sprite consists out of sequence of images which are creating the animation
 */
class ASprite
{
private:
    TPicturesList _picturesList;
    
public:
	ASprite(const std::string& prefix);
	ASprite(const ASprite& sprite);
    ~ASprite();
	ASprite& operator=(const ASprite& rv);
    bool operator ==(const ASprite & obj) const;

    const TPicturesList& picturesList() const;
    const APicture& findPicture(const std::string& pictureName) const;
    void addPicture(const APicture& newPicture);

    int spriteHeight() const;
    int spriteWidth() const;
    int spriteSize() const;
	std::string spritesPrefix;
};

//=============================================================================

};  //  namespace spcWAD

//=============================================================================

#endif  //  SPCWAD_ASPRITE_H
