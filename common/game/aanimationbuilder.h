#ifndef SPCTGAME_AANIMATIONBUILDER_H
#define SPCTGAME_AANIMATIONBUILDER_H

//==============================================================================

#include "aopengltexture.h"
#include "asprite.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

typedef std::vector<spcWAD::APicture> TFrameProjectionsList;
typedef TFrameProjectionsList::iterator TFrameProjectionsListIter;
typedef TFrameProjectionsList::const_iterator TFrameProjectionsListConstIter;

typedef std::list<TFrameProjectionsList> TAnimationFramesList;
typedef TAnimationFramesList::iterator TAnimationFramesListIter;
typedef TAnimationFramesList::const_iterator TAnimationFramesListConstIter;

//==============================================================================

class AAnimationBuilder
{
private:
    TFrameProjectionsList shouldbeMirrored(const spcWAD::APicture& picture, const std::string& pictureName, const std::string& spritePrefix) const;

public:
    AAnimationBuilder();
    ~AAnimationBuilder();
    
    TAnimationFramesList buildAnimation(const spcWAD::ASprite& wadSprite) const;
    
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AANIMATIONBUILDER_H
