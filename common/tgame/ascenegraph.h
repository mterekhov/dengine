#ifndef SPCTGAME_ADATASTORAGE_H
#define SPCTGAME_ADATASTORAGE_H

//==============================================================================

#include <list>

//==============================================================================

namespace spcTGame
{

//==============================================================================

class ASceneNode;
    
//==============================================================================

typedef std::list<ASceneNode> TSceneNodesList;
typedef TSceneNodesList::iterator TSceneNodesListIter;
typedef TSceneNodesList::const_iterator TSceneNodesListConstIter;

//==============================================================================

class ASceneGraph
{
private:
    TSceneNodesList _texturedNodesList;
    TSceneNodesList _solidNodesList;

public:
    ASceneGraph();
    ~ASceneGraph();
    
    void addObject(const ASceneNode& object);
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ADATASTORAGE_H
