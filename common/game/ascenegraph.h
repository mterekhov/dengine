#ifndef SPCTGAME_ADATASTORAGE_H
#define SPCTGAME_ADATASTORAGE_H

//==============================================================================

#include <list>
#include "atexturemanager.h"
#include "anodeobject.h"
#include "ascenenode.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ASceneNode;
    
//==============================================================================

typedef std::list<ASceneNode> TSceneNodesList;
typedef TSceneNodesList::iterator TSceneNodesListIter;
typedef TSceneNodesList::const_iterator TSceneNodesListConstIter;

typedef std::list<ANodeObject *> TObjectsList;
typedef TObjectsList::iterator TObjectsListIter;
typedef TObjectsList::const_iterator TObjectsListConstIter;

//==============================================================================

class ASceneGraph
{
private:
    TSceneNodesList _uiElementsList;
    TSceneNodesList _texturedNodesList;
    TSceneNodesList _solidNodesList;
    
    TObjectsList _objectsList;

public:
    ATextureManager _textureManager;

    ASceneGraph();
    ~ASceneGraph();
    
    ASceneNode& addUIElement(ANodeObject *object, const ESceneNodeTrasnsparency nodeTransparency = ESCENENODETRANSPARENCY_NONE);
    ASceneNode& addObject(ANodeObject *object, const ESceneNodeType nodeType, const ESceneNodeTrasnsparency nodeTransparency = ESCENENODETRANSPARENCY_NONE);
    TSceneNodesList& texturedNodes();
    TSceneNodesList& uiElementsNodes();
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ADATASTORAGE_H
