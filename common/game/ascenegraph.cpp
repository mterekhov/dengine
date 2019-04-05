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
    
ASceneNode& ASceneGraph::addObject(ANodeObject* object, const ESceneNodeType nodeType, const ESceneNodeTrasnsparency nodeTransparency)
{
    _objectsList.push_back(object);
    ASceneNode newNode(object, AVector(1.0f, 1.0f, 1.0f), AVector(), 0, APoint(), nodeType, nodeTransparency);

    switch (nodeType)
    {
        case ESCENENODETYPE_TEXTURED:
            _texturedNodesList.push_back(newNode);
            return _texturedNodesList.back();
        break;
            
        case ESCENENODETYPE_SOLID:
            _solidNodesList.push_back(newNode);
            return _solidNodesList.back();
        break;
    }
    
    return _texturedNodesList.back();
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
