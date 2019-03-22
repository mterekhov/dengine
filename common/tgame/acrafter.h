#ifndef SPCTGAME_ACRAFTER_H
#define SPCTGAME_ACRAFTER_H

//==============================================================================
//
//  The main purpose of this class is to render everything we need and keep it in memory
//
//==============================================================================

#include <list>

#include "atexturedblock.h"
#include "asolidblock.h"
#include "ablock.h"
#include "atexturemanager.h"
#include "awell.h"
#include "adatastorage.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

typedef std::list<ARObject*> TRObjectsList;
typedef TRObjectsList::iterator TRObjectsListIter;
typedef TRObjectsList::const_iterator TRObjectsListConstIter;

//==============================================================================

class ACrafter
{
private:
    ATextureManager _textureManager;
    ADataStorage& _dataStorage;
    TRObjectsList _texturedRenderList;
    TRObjectsList _solidRenderList;

    void generateTexturedRenderList(const TFormationList& formations, const ATexture& texture);
    
    void renewRenderLists();
    void clearAllLists();
    void clearTextureList();
    void clearRenderList();
    TBool clearList(TRObjectsList& renderList);
    
    void renderContent();
    void renderList(const TRObjectsList& renderList);
    
    TBool addObjectForRender(ARObject* object);
    ATexturedBlock* createTexturedBlock(AFormation* formation, const ATexture& texture);
    ASolidBlock* createSolidBlock(AFormation* formation);
    AColoredBlock* createColoredBlock(AFormation* formation);
    AWell* createWell();
    void createDroppedBlocks();
    
public:
    ACrafter(ADataStorage& dataStorage);
    virtual ~ACrafter();

    void refreshRenderLists();
    void processRender();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ACRAFTER_H
