//#include <math.h>
#include <time.h>
#include <stdlib.h>

#include "adatastorage.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

ADataStorage::ADataStorage() : _currentFormation(0), _wellFormation(0)
{
    srand(static_cast<TUint>(time(0)));
}

//==============================================================================

ADataStorage::~ADataStorage()
{
    destroyAllFormations();
}

//==============================================================================

TFloat ADataStorage::cellSize()
{
    return 1.0f;
}

//==============================================================================

#pragma mark - Formation list management -

//==============================================================================

AFormation* ADataStorage::createFormation1()
{
    AFormation* newFormation = AFormationFactory::createFormation1();

    return createFormation(newFormation);
}

//==============================================================================

AFormation* ADataStorage::createFormation2()
{
    AFormation* newFormation = AFormationFactory::createFormation2();

    return createFormation(newFormation);
}

//==============================================================================

AFormation* ADataStorage::createFormation3()
{
    AFormation* newFormation = AFormationFactory::createFormation3();

    return createFormation(newFormation);
}

//==============================================================================

AFormation* ADataStorage::createFormation4()
{
    AFormation* newFormation = AFormationFactory::createFormation4();

    return createFormation(newFormation);
}

//==============================================================================

AFormation* ADataStorage::createFormation5()
{
    AFormation* newFormation = AFormationFactory::createFormation5();

    return createFormation(newFormation);
}

//==============================================================================

AFormation* ADataStorage::createFormation6()
{
    AFormation* newFormation = AFormationFactory::createFormation6();

    return createFormation(newFormation);
}

//==============================================================================

AFormation* ADataStorage::createFormation7()
{
    AFormation* newFormation = AFormationFactory::createFormation7();

    return createFormation(newFormation);
}

//==============================================================================

AFormation* ADataStorage::createFormation8()
{
    AFormation* newFormation = AFormationFactory::createFormation8();

    return createFormation(newFormation);
}

//==============================================================================

AFormation* ADataStorage::createFormation9()
{
    AFormation* newFormation = AFormationFactory::createFormation9();

    return createFormation(newFormation);
}

//==============================================================================

AFormation* ADataStorage::createFormation10()
{
    AFormation* newFormation = AFormationFactory::createFormation10();

    return createFormation(newFormation);
}

//==============================================================================

AFormation* ADataStorage::createRandomFormation()
{
    TUint formationIndex = rand() % FORMATIONS_COUNT;
    AFormation* newFormation = 0;

    switch (formationIndex)
    {
        case FORMATIONS_ONE:
            newFormation = createFormation1();
        break;
        
        case FORMATIONS_TWO:
            newFormation = createFormation2();
        break;
        
        case FORMATIONS_THREE:
            newFormation = createFormation3();
        break;
        
        case FORMATIONS_FOUR:
            newFormation = createFormation4();
        break;
        
        case FORMATIONS_FIVE:
            newFormation = createFormation5();
        break;
        
        case FORMATIONS_SIX:
            newFormation = createFormation6();
        break;
        
        case FORMATIONS_SEVEN:
            newFormation = createFormation7();
        break;
        
        case FORMATIONS_EIGHT:
            newFormation = createFormation8();
        break;
    };
    
    return newFormation;
}

//==============================================================================

#pragma mark - Current formation -

//==============================================================================

void ADataStorage::assignCurrentFormation(AFormation* formation)
{
    _currentFormation = createFormation(formation);
}

//==============================================================================

void ADataStorage::replaceCurrentFormation(AFormation* formation)
{
    deleteFormation(_currentFormation);
    _currentFormation = createFormation(formation);
}

//==============================================================================

AFormation* ADataStorage::currentFormation()
{
    return _currentFormation;
}

//==============================================================================

#pragma mark - Well formation -

//==============================================================================

AFormation* ADataStorage::createWellFormation(const TFloat width, const TFloat height, const TFloat depth)
{
    deleteFormation(_wellFormation);
    AFormation* newFormation = AFormationFactory::createFormation(width, height, depth);
    _wellFormation = createFormation(newFormation);
    
    return _wellFormation;
}

//==============================================================================

AFormation* ADataStorage::wellFormation()
{
    return _wellFormation;
}

//==============================================================================

TFloat ADataStorage::wellWidth()
{
    return _wellFormation->width();
}

//==============================================================================

TFloat ADataStorage::wellHeight()
{
    return _wellFormation->height();
}

//==============================================================================

TFloat ADataStorage::wellDepth()
{
    return _wellFormation->levelsCount();
}

//==============================================================================

#pragma mark - Drop logic -

//==============================================================================

void ADataStorage::dropCurrentFormation()
{
    makeFormationDropped(_currentFormation);
    assignCurrentFormation(createRandomFormation());
}

//==============================================================================

const TFormationList& ADataStorage::droppedFormationsList()
{
    return _droppedFormationsList;
}

//==============================================================================

#pragma mark - Routine -

//==============================================================================

AFormation* ADataStorage::createFormation(AFormation *formation)
{
    return pushFormation(formation);
}

//==============================================================================

AFormation* ADataStorage::pushFormation(AFormation* pushFormation)
{
    _formationList.push_back(pushFormation);

    return _formationList.back();
}

//==============================================================================

void ADataStorage::destroyAllFormations()
{
    for (TFormationListIter iter = _formationList.begin(); iter != _formationList.end(); iter++)
    {
        AFormation *formation = *iter;
        deleteFormation(formation);
    }
}

//==============================================================================

void ADataStorage::deleteFormation(AFormation* formation)
{
    if (formation == 0)
        return;
    
    _formationList.remove(formation);
    delete formation;
}

//==============================================================================

void ADataStorage::makeFormationDropped(AFormation *formation)
{
    if (formation == 0)
        return;

    _droppedFormationsList.push_back(formation);
}

//==============================================================================

}   //  namespace spcTGame
