#ifndef SPCTGAME_ACHANGER_H
#define SPCTGAME_ACHANGER_H

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ASceneNode;

//==============================================================================

class AChanger
{
public:
    AChanger();
    virtual ~AChanger();
    
    virtual void make(ASceneNode& sceneNode);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ACHANGER_H
