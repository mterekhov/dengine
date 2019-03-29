#include "ascenenode.h"
#include "anodeobject.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
ASceneNode::ASceneNode() : _nodeType(NODETYPE_SOLID), _position(APoint()), _nodeObject(0)
{
}

//==============================================================================

ASceneNode::ASceneNode(const ASceneNode& sceneNode) : _nodeType(sceneNode._nodeType), _nodeObject(sceneNode._nodeObject), _position(sceneNode._position)
{
    
}
    
//==============================================================================
    
ASceneNode::ASceneNode(ANodeObject* object, const APoint& position, const ENodeType nodeType) : _nodeObject(object), _nodeType(nodeType), _position(position)
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

ENodeType ASceneNode::nodeType() const
{
    return _nodeType;
}

//==============================================================================
    
}   //  namespace spcTGame

