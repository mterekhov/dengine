#include "aanimation.h"
#include "ascenenode.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

AAnimation::AAnimation() : _animationTrigger(0), _currentFramesCount(0)
{
}

//==============================================================================

AAnimation::~AAnimation()
{
}

//==============================================================================

void AAnimation::appendChanger(AChanger *newChanger)
{
    if (newChanger == 0)
    {
        return;
    }

    _changersList.push_back(newChanger);
}

//==============================================================================

void AAnimation::animate(ASceneNode& sceneNode)
{
    if (_animationTrigger <= 0)
    {
        return;
    }
    
    TInt diff = _animationTrigger - ++_currentFramesCount;
    if (diff > 0)
    {
        return;
    }

    for (TChangersListConstIter iter = _changersList.begin(); iter != _changersList.end(); iter++)
    {
        (*iter)->make(sceneNode);
    }

    _currentFramesCount = 0;
}

//==============================================================================

}   //  namespace spcTGame
