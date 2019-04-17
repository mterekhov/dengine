#ifndef SPCTGAME_ADATASTORAGE_H
#define SPCTGAME_ADATASTORAGE_H

//==============================================================================

#include <list>
#include "atexturemanager.h"
#include "anodeobject.h"
#include "ascenenode.h"
#include "abutton.h"

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

typedef std::list<AButton> TButtonsList;
typedef TButtonsList::iterator TButtonsListIter;
typedef TButtonsList::const_iterator TButtonsListConstIter;
    
    
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
    TSceneNodesListIter addObject(ANodeObject *object, const ESceneNodeType nodeType, const ESceneNodeTrasnsparency nodeTransparency = ESCENENODETRANSPARENCY_NONE);
    void removeObject(TSceneNodesListIter nodeIter);
    TSceneNodesList& texturedNodes();
    TSceneNodesList& uiElementsNodes();
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ADATASTORAGE_H
