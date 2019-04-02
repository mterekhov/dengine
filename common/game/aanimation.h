#ifndef SPCTGAME_AANIMATION_H
#define SPCTGAME_AANIMATION_H

//==============================================================================

#include "aopengltexture.h"
#include "asprite.h"
#include "achanger.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

class ANodeObject;
    
//==============================================================================

typedef std::vector<spcWAD::APicture> TFrameProjectionsList;
typedef TFrameProjectionsList::iterator TFrameProjectionsListIter;
typedef TFrameProjectionsList::const_iterator TFrameProjectionsListConstIter;

typedef std::list<TFrameProjectionsList> TAnimationFramesList;
typedef TAnimationFramesList::iterator TAnimationFramesListIter;
typedef TAnimationFramesList::const_iterator TAnimationFramesListConstIter;

typedef std::list<AChanger *> TChangersList;
typedef TChangersList::iterator TChangersListIter;
typedef TChangersList::const_iterator TChangersListConstIter;
    
//==============================================================================

class AAnimation
{
private:
    TInt _currentFramesCount;
    TChangersList _changersList;
    
public:
    AAnimation();
    ~AAnimation();
    
    void appendChanger(AChanger *newChanger);
    void animate(ANodeObject *nodeObject);
    
    TInt _animationTrigger;
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AANIMATION_H
