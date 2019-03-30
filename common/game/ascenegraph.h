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
    TSceneNodesList _texturedNodesList;
    TSceneNodesList _solidNodesList;
    
    TObjectsList _objectsList;

public:
    ATextureManager _textureManager;

    ASceneGraph();
    ~ASceneGraph();
    
    void addObject(ANodeObject *object, const APoint& position, const ESceneNodeType nodeType, const ESceneNodeTrasnsparency nodeTransparency = ESCENENODETRANSPARENCY_NONE);
    const TSceneNodesList& texturedNodes() const;
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ADATASTORAGE_H
