#ifndef SPCTGAME_ACRAFTER_H
#define SPCTGAME_ACRAFTER_H

//==============================================================================
//
//  The main purpose of this class is to render everything we need and keep it in memory
//
//==============================================================================

#include <list>

#include "atexturemanager.h"
#include "ascenegraph.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

class ASceneNode;
    
//==============================================================================

class ARenderService
{
private:
    ATextureManager _textureManager;
    ASceneGraph& _sceneGraph;

    void renderContent();
    
public:
    ARenderService(ASceneGraph& dataStorage);
    ~ARenderService();
    
    void processRender();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ACRAFTER_H