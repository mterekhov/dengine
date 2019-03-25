#include "aformationrotategamestep.h"
#include "keymaps.h"
#include "aformationoperations.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

AFormationRotateGameStep::AFormationRotateGameStep(const TUint buttonCode) : _buttonCode(buttonCode)
{
}

//==============================================================================

AFormationRotateGameStep::~AFormationRotateGameStep()
{
}

//==============================================================================

void AFormationRotateGameStep::executeStep(ASceneGraph &dataStorage)
{
    switch (_buttonCode)
    {
        case EKEYCODES_ROTATE_X:
            rotateX(dataStorage);
        break;
        
        case EKEYCODES_ROTATE_Y:
            rotateY(dataStorage);
        break;
        
        case EKEYCODES_ROTATE_Z:
            rotateZ(dataStorage);
        break;
            
        default:
        break;
    }
}

//==============================================================================

void AFormationRotateGameStep::rotateX(ASceneGraph &dataStorage)
{
    AMatrix m = AMatrix::rotationX(M_PI_2);
    rotate(m, dataStorage);
}

//==============================================================================

void AFormationRotateGameStep::rotateY(ASceneGraph &dataStorage)
{
    AMatrix m = AMatrix::rotationY(M_PI_2);
    rotate(m, dataStorage);
}

//==============================================================================

void AFormationRotateGameStep::rotateZ(ASceneGraph &dataStorage)
{
    AMatrix m = AMatrix::rotationZ(M_PI_2);
    rotate(m, dataStorage);
}

//==============================================================================

void AFormationRotateGameStep::rotate(const AMatrix& m, ASceneGraph &dataStorage)
{
    AFormation* rotatedFormation = AFormationOperations::createRotatedFrustumFormation(*dataStorage.currentFormation(),
                                                                                   m,
                                                                                   AFrustumBorder(dataStorage.wellHeight(), dataStorage.wellDepth(), dataStorage.wellWidth()));
    dataStorage.replaceCurrentFormation(rotatedFormation);
}

//==============================================================================

}   //  namespace spcTGame
