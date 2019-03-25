#include "aformationmovegamestep.h"
#include "keymaps.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

AFormationMoveGameStep::AFormationMoveGameStep(const TUint buttonCode) : _buttonCode(buttonCode)
{
}

//==============================================================================

AFormationMoveGameStep::~AFormationMoveGameStep()
{
}

//==============================================================================

void AFormationMoveGameStep::executeStep(ASceneGraph &dataStorage)
{
    switch (_buttonCode)
    {
        case EKEYCODES_DOWN:
            moveCurrentFormationDown(dataStorage);
        break;
        
        case EKEYCODES_UP:
            moveCurrentFormationUp(dataStorage);
        break;
        
        case EKEYCODES_LEFT:
            moveCurrentFormationLeft(dataStorage);
        break;
        
        case EKEYCODES_RIGHT:
            moveCurrentFormationRight(dataStorage);
        break;
            
        default:
            return;
        break;
    }
}

//==============================================================================

void AFormationMoveGameStep::moveCurrentFormationRight(ASceneGraph &dataStorage)
{
    AFormation* currentFormation = dataStorage.currentFormation();
    APoint position = currentFormation->gridSpacePosition();
    position.z += dataStorage.cellSize();

    if (isBreakingWellBound(position, currentFormation, dataStorage) == false)
        currentFormation->gridSpacePosition(position);
}

//==============================================================================

void AFormationMoveGameStep::moveCurrentFormationLeft(ASceneGraph &dataStorage)
{
    AFormation* currentFormation = dataStorage.currentFormation();
    APoint position = currentFormation->gridSpacePosition();
    position.z -= dataStorage.cellSize();

    if (isBreakingWellBound(position, currentFormation, dataStorage) == false)
        currentFormation->gridSpacePosition(position);
}

//==============================================================================

void AFormationMoveGameStep::moveCurrentFormationDown(ASceneGraph &dataStorage)
{
    AFormation* currentFormation = dataStorage.currentFormation();
    APoint position = currentFormation->gridSpacePosition();
    position.x -= dataStorage.cellSize();

    if (isBreakingWellBound(position, currentFormation, dataStorage) == false)
        currentFormation->gridSpacePosition(position);
}

//==============================================================================

void AFormationMoveGameStep::moveCurrentFormationUp(ASceneGraph &dataStorage)
{
    AFormation* currentFormation = dataStorage.currentFormation();
    APoint position = currentFormation->gridSpacePosition();
    position.x += dataStorage.cellSize();

    if (isBreakingWellBound(position, currentFormation, dataStorage) == false)
        currentFormation->gridSpacePosition(position);
}

//==============================================================================

TBool AFormationMoveGameStep::isBreakingWellBound(const APoint& position, const AFormation* formation, ASceneGraph &dataStorage)
{
    //  check top border
    if ((position.x + formation->height()) > dataStorage.wellHeight() ||
         position.x < 0)
        return true;
        
    if ((position.z + formation->width()) > dataStorage.wellWidth() ||
         position.z < 0)
        return true;
        
    return false;
}

//==============================================================================

}   //  namespace spcTGame
