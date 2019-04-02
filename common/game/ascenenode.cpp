#include "ascenenode.h"
#include "anodeobject.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
ASceneNode::ASceneNode() : _nodeType(ESCENENODETYPE_SOLID), _rotation(AQuaternion()), _scale(AVector(1.0f, 1.0f, 1.0f)), _position(APoint()), _nodeObject(0), _transparencyType(ESCENENODETRANSPARENCY_NONE)
{
}

//==============================================================================

ASceneNode::ASceneNode(const ASceneNode& sceneNode) : _scale(sceneNode._scale), _rotation(sceneNode._rotation), _nodeType(sceneNode._nodeType), _nodeObject(sceneNode._nodeObject), _position(sceneNode._position), _transparencyType(sceneNode._transparencyType)
{
    
}
    
//==============================================================================
    
ASceneNode::ASceneNode(ANodeObject* object, const AVector& scale, const AVector& rotationVector, const TFloat rotationAngle, const APoint& position, const ESceneNodeType nodeType, const ESceneNodeTrasnsparency nodeTransparency) : _nodeObject(object), _nodeType(nodeType), _position(position), _transparencyType(nodeTransparency), _rotation(AQuaternion(rotationVector, rotationAngle)), _scale(scale)
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
    _rotation = rv._rotation;
    _scale = rv._scale;
    _nodeObject = rv._nodeObject;
    _transparencyType = rv._transparencyType;

    return *this;
}

//==============================================================================
    
void ASceneNode::attachAnimation(const AAnimation& newAnimation)
{
    _animation = newAnimation;
}

//==============================================================================
    
void ASceneNode::renderObject() const
{
    if (_nodeObject == 0)
    {
        return;
    }
    
    _nodeObject->renderObject();
}

//==============================================================================

void ASceneNode::applyAnimation()
{
    _animation.animate(_nodeObject);
}

//==============================================================================

void ASceneNode::changePosition(const APoint& newPoint)
{
    _position = newPoint;
}

//==============================================================================

void ASceneNode::changeRotation(const AQuaternion& newRotation)
{
    _rotation = newRotation;
}

//==============================================================================

void ASceneNode::changeScale(const AVector& newScale)
{
    _scale = newScale;
}

//==============================================================================
    
const APoint& ASceneNode::position() const
{
    return _position;
}

//==============================================================================

const AVector& ASceneNode::scale() const
{
    return _scale;
}

//==============================================================================

const AQuaternion& ASceneNode::rotation() const
{
    return _rotation;
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

