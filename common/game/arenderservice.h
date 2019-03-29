#ifndef SPCTGAME_ACRAFTER_H
#define SPCTGAME_ACRAFTER_H

//==============================================================================
//
//  The main purpose of this class is to render everything we need and keep it in memory
//
//==============================================================================

#include <list>

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
    ASceneGraph& _sceneGraph;

    void renderTexturedObjects();
    
public:
    ARenderService(ASceneGraph& dataStorage);
    ~ARenderService();
    
    void processRender();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ACRAFTER_H
