#ifndef SPCTGAME_ACHANGER_H
#define SPCTGAME_ACHANGER_H

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ANodeObject;

//==============================================================================

class AChanger
{
public:
    AChanger();
    virtual ~AChanger();
    
    virtual void make(ANodeObject *object);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ACHANGER_H
