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

void ACreateWellGameStep::executeStep(ADataStorage &dataStorage)
{
    dataStorage.createWellFormation(7, 7, 15);
}

//==============================================================================

}   //  namespace spcTGame
