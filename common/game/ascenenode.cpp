#include "ascenenode.h"
#include "anodeobject.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
ASceneNode::ASceneNode() : _nodeType(ESCENENODETYPE_SOLID), _position(APoint()), _nodeObject(0), _transparencyType(ESCENENODETRANSPARENCY_NONE)
{
}

//==============================================================================

ASceneNode::ASceneNode(const ASceneNode& sceneNode) : _nodeType(sceneNode._nodeType), _nodeObject(sceneNode._nodeObject), _position(sceneNode._position), _transparencyType(sceneNode._transparencyType)
{
    
}
    
//==============================================================================
    
ASceneNode::ASceneNode(ANodeObject* object, const APoint& position, const ESceneNodeType nodeType, const ESceneNodeTrasnsparency nodeTransparency) : _nodeObject(object), _nodeType(nodeType), _position(position), _transparencyType(nodeTransparency)
{
}

//==============================================================================

ASceneNode::~ASceneNode()
{
}

//==============================================================================

ASceneNode& ASceneNode::operator=(const ASceneNode& rv)
{
    if (this == &rv)
    {
        return *this;
    }

    _nodeType = rv._nodeType;
    _position = rv._position;
    _nodeObject = rv._nodeObject;
    _transparencyType = rv._transparencyType;

    return *this;
}

//==============================================================================
    
void ASceneNode::renderObject() const
{
}

//==============================================================================

const APoint& ASceneNode::position() const
{
    return _position;
}
    
//==============================================================================

const ANodeObject* ASceneNode::nodeObject() const
{
    return _nodeObject;
}

//==============================================================================

ESceneNodeType ASceneNode::nodeType() const
{
    return _nodeType;
}

//==============================================================================

ESceneNodeTrasnsparency ASceneNode::transparencyType() const
{
    return _transparencyType;
}

//==============================================================================

}   //  namespace spcTGame

