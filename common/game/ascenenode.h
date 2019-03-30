#ifndef SPCTGAME_ASceneNode_H
#define SPCTGAME_ASceneNode_H

//==============================================================================

#include "apoint.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

class ANodeObject;
    
enum ESceneNodeType
{
    ESCENENODETYPE_SOLID,
    ESCENENODETYPE_TEXTURED
};

enum ESceneNodeTrasnsparency
{
    ESCENENODETRANSPARENCY_FULL,    //  full transparent object
    ESCENENODETRANSPARENCY_HALF,    //  half transparent object
    ESCENENODETRANSPARENCY_NONE //  non transparntr object
};

//==============================================================================

class ASceneNode
{
protected:
    ESceneNodeType _nodeType;
    ESceneNodeTrasnsparency _transparencyType;
    APoint _position;
    ANodeObject *_nodeObject;

public:
    ASceneNode();
    ASceneNode(const ASceneNode& sceneNode);
    ASceneNode(ANodeObject* object, const APoint& position, const ESceneNodeType nodeType, const ESceneNodeTrasnsparency nodeTransparency);
    ~ASceneNode();
    ASceneNode& operator=(const ASceneNode& rv);

    virtual void renderObject() const;
    
    ESceneNodeTrasnsparency transparencyType() const;
    ESceneNodeType nodeType() const;
    const APoint& position() const;
    const ANodeObject* nodeObject() const;
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ASceneNode_H
