#include "acreatewellgamestep.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

ACreateWellGameStep::ACreateWellGameStep()
{
}

//==============================================================================

ACreateWellGameStep::~ACreateWellGameStep()
{
}

//==============================================================================

void ACreateWellGameStep::executeStep(ASceneGraph &dataStorage)
{
    dataStorage.createWellFormation(7, 7, 15);
}

//==============================================================================

}   //  namespace spcTGame
