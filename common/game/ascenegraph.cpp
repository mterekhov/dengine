#include "ascenegraph.h"
#include "ascenenode.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

ASceneGraph::ASceneGraph()
{
}

//==============================================================================

ASceneGraph::~ASceneGraph()
{
}

//==============================================================================

void ASceneGraph::addObject(ANodeObject* object, const APoint& position, const ESceneNodeType nodeType, const ESceneNodeTrasnsparency nodeTransparency)
{
    _objectsList.push_back(object);
    ASceneNode newNode(object, position, nodeType, nodeTransparency);
    switch (nodeType)
    {
        case ESCENENODETYPE_TEXTURED:
            _texturedNodesList.push_back(newNode);
        break;
            
        case ESCENENODETYPE_SOLID:
            _solidNodesList.push_back(newNode);
        break;
    }
}

//==============================================================================
    
const TSceneNodesList& ASceneGraph::texturedNodes() const
{
    return _texturedNodesList;
}

//==============================================================================

}   //  namespace spcTGame
