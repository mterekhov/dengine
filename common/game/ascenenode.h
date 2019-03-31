#ifndef SPCTGAME_ASceneNode_H
#define SPCTGAME_ASceneNode_H

//==============================================================================

#include "apoint.h"
#include "avector.h"
#include "aquaternion.h"
#include "aanimation.h"

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
private:
    ESceneNodeType _nodeType;
    ESceneNodeTrasnsparency _transparencyType;
    APoint _position;
    AVector _scale;
    AQuaternion _rotation;
    ANodeObject *_nodeObject;
    AAnimation _animation;

public:
    ASceneNode();
    ASceneNode(const ASceneNode& sceneNode);
    ASceneNode(ANodeObject* object, const AVector& scale, const AVector& rotationVector, const TFloat rotationAngle, const APoint& position, const ESceneNodeType nodeType, const ESceneNodeTrasnsparency nodeTransparency);
    ~ASceneNode();
    ASceneNode& operator=(const ASceneNode& rv);

    virtual void renderObject() const;
    virtual void applyAnimation();
    
    void attachAnimation(const AAnimation& newAnimation);

    ESceneNodeTrasnsparency transparencyType() const;
    ESceneNodeType nodeType() const;
    const APoint& position() const;
    const AQuaternion& rotation() const;
    const AVector& scale() const;
    
    void changePosition(const APoint& newPoint);
    void changeRotation(const AQuaternion& newRotation);
    void changeScale(const AVector& newScale);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ASceneNode_H
