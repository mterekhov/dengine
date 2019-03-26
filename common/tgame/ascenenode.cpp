#include "ascenenode.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
ASceneNode::ASceneNode() : _nodeType(NODETYPE_SOLID)
{
}

//==============================================================================

ASceneNode::ASceneNode(const ASceneNode& object) : _nodeType(object._nodeType)
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

    return *this;
}

//==============================================================================
    
void ASceneNode::renderObject()
{
}

//==============================================================================

ENodeType ASceneNode::nodeType() const
{
    return _nodeType;
}

//==============================================================================
    
}   //  namespace spcTGame

