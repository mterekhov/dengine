#include "aformationdropgamestep.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

AFormationDropGameStep::AFormationDropGameStep()
{
}

//==============================================================================

AFormationDropGameStep::~AFormationDropGameStep()
{
}

//==============================================================================

void AFormationDropGameStep::executeStep(ADataStorage &dataStorage)
{
    //  assign drop position to current formation
    AFormation *formationToDrop = dataStorage.currentFormation();
    APoint dropPosition = findDropPosition(formationToDrop);
    formationToDrop->gridSpacePosition(dropPosition);

    //  mark current formation as dropped
    //  and generate new current formation
    dataStorage.dropCurrentFormation();
}

//==============================================================================

APoint AFormationDropGameStep::findDropPosition(AFormation* formation)
{
    APoint dropPosition = formation->gridSpacePosition();
    dropPosition.y = 0;
//    AFormation* wellFormation = _dataStorage.wellFormation();
//
//    for (TInt l = 0; l < formation->levelsCount(); l++)
//    {
//        for (TInt i = 0; i < formation->height(); i++)
//        {
//            for (TInt j = 0; j < formation->width(); j++)
//            {
//                TData value = formation->item(j, i, l);
//                if (value == EDATASTATE_RENDERABLE)
//                {
//                    
//                }
//            }
//        }
//    }
    
    return dropPosition;
}

//==============================================================================

}   //  namespace spcTGame
