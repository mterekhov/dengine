#ifndef SPCTGAME_ASceneNode_H
#define SPCTGAME_ASceneNode_H

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
enum ENodeType
{
    NODETYPE_SOLID,
    NODETYPE_TEXTURED
};

//==============================================================================

class ASceneNode
{
protected:
    ENodeType _nodeType;
    
public:
    ASceneNode();
    ASceneNode(const ASceneNode& object);
    virtual ~ASceneNode();
    ASceneNode& operator=(const ASceneNode& rv);

    virtual void renderObject();
    ENodeType nodeType() const;
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ASceneNode_H
