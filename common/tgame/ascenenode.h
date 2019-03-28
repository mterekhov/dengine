#ifndef SPCTGAME_ASceneNode_H
#define SPCTGAME_ASceneNode_H

//==============================================================================

#include "apoint.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

class ANodeObject;
    
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
    APoint _position;
    ANodeObject *_nodeObject;

public:
    ASceneNode();
    ASceneNode(const ASceneNode& sceneNode);
    ASceneNode(ANodeObject* object, const APoint& position, const ENodeType nodeType);
    ~ASceneNode();
    ASceneNode& operator=(const ASceneNode& rv);

    virtual void renderObject() const;
    
    ENodeType nodeType() const;
    const APoint& position() const;
    const ANodeObject* nodeObject() const;
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ASceneNode_H
