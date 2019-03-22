#ifndef SPCTGAME_AROBJECT_H
#define SPCTGAME_AROBJECT_H

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
enum EObjectType
{
    OBJECTTYPE_SOLID,
    OBJECTTYPE_TEXTURED
};

//==============================================================================

class ARObject
{
protected:
    EObjectType _objectType;
    
public:
    ARObject();
    ARObject(const ARObject& object);
    virtual ~ARObject();
    
    virtual void renderObject();
    EObjectType objectType() const;
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AROBJECT_H
