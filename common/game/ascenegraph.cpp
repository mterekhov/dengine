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

void ASceneGraph::addObject(ANodeObject* object, const APoint& position, const ENodeType nodeType)
{
    _objectsList.push_back(object);
    ASceneNode newNode(object, position, nodeType);
    switch (nodeType)
    {
        case NODETYPE_TEXTURED:
            _texturedNodesList.push_back(newNode);
        break;
            
        case NODETYPE_SOLID:
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
