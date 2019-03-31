#ifndef SPCTGAME_AANIMATION_H
#define SPCTGAME_AANIMATION_H

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

class AAnimation
{
private:
    void animateTexture();
    void animateTranslation();
    void animateScale();
    void animateRotation();
    
public:
    AAnimation();
    ~AAnimation();
    
    void animate();
    
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AANIMATIONBUILDER_H
