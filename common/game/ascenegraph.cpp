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

ASceneNode& ASceneGraph::addUIElement(ANodeObject *object, const ESceneNodeTrasnsparency nodeTransparency)
{
    _objectsList.push_back(object);
    ASceneNode newNode(object, AVector(1.0f, 1.0f, 1.0f), AVector(), 0, APoint(), ESCENENODETYPE_TEXTURED, nodeTransparency);
    _uiElementsList.push_back(newNode);
    
    return _uiElementsList.back();
}
    
//==============================================================================

void ASceneGraph::removeObject(TSceneNodesListIter nodeIter)
{
    ANodeObject *object = nodeIter->nodeObject();
    _objectsList.remove(object);
    delete object;
    
    switch (nodeIter->nodeType())
    {
        case ESCENENODETYPE_TEXTURED:
            _texturedNodesList.erase(nodeIter);
        break;
            
        case ESCENENODETYPE_SOLID:
            _solidNodesList.erase(nodeIter);
        break;
    }
}

//==============================================================================

TSceneNodesListIter ASceneGraph::addObject(ANodeObject* object, const ESceneNodeType nodeType, const ESceneNodeTrasnsparency nodeTransparency)
{
    _objectsList.push_back(object);
    ASceneNode newNode(object, AVector(1.0f, 1.0f, 1.0f), AVector(), 0, APoint(), nodeType, nodeTransparency);

    switch (nodeType)
    {
        case ESCENENODETYPE_TEXTURED:
            _texturedNodesList.push_back(newNode);
            return --(_texturedNodesList.end());
        break;
            
        case ESCENENODETYPE_SOLID:
            _solidNodesList.push_back(newNode);
            return --_solidNodesList.end();
        break;
    }
    
    return --_texturedNodesList.end();
}

//==============================================================================
    
TSceneNodesList& ASceneGraph::texturedNodes()
{
    return _texturedNodesList;
}

//==============================================================================

TSceneNodesList& ASceneGraph::uiElementsNodes()
{
    return _uiElementsList;
}

//==============================================================================

}   //  namespace spcTGame
