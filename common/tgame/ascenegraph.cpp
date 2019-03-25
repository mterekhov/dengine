//#include <math.h>
#include <time.h>
#include <stdlib.h>

#include "adatastorage.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

ASceneGraph::ASceneGraph() : _currentFormation(0), _wellFormation(0)
{
    srand(static_cast<TUint>(time(0)));
}

//==============================================================================

ASceneGraph::~ASceneGraph()
{
    destroyAllFormations();
}

//==============================================================================

TFloat ASceneGraph::cellSize()
{
    return 1.0f;
}

//==============================================================================

#pragma mark - Formation list management -

//==============================================================================

AFormation* ASceneGraph::createFormation1()
{
    AFormation* newFormation = AFormationFactory::createFormation1();

    return createFormation(newFormation);
}

//==============================================================================

AFormation* ASceneGraph::createFormation2()
{
    AFormation* newFormation = AFormationFactory::createFormation2();

    return createFormation(newFormation);
}

//==============================================================================

AFormation* ASceneGraph::createFormation3()
{
    AFormation* newFormation = AFormationFactory::createFormation3();

    return createFormation(newFormation);
}

//==============================================================================

AFormation* ASceneGraph::createFormation4()
{
    AFormation* newFormation = AFormationFactory::createFormation4();

    return createFormation(newFormation);
}

//==============================================================================

AFormation* ASceneGraph::createFormation5()
{
    AFormation* newFormation = AFormationFactory::createFormation5();

    return createFormation(newFormation);
}

//==============================================================================

AFormation* ASceneGraph::createFormation6()
{
    AFormation* newFormation = AFormationFactory::createFormation6();

    return createFormation(newFormation);
}

//==============================================================================

AFormation* ASceneGraph::createFormation7()
{
    AFormation* newFormation = AFormationFactory::createFormation7();

    return createFormation(newFormation);
}

//==============================================================================

AFormation* ASceneGraph::createFormation8()
{
    AFormation* newFormation = AFormationFactory::createFormation8();

    return createFormation(newFormation);
}

//==============================================================================

AFormation* ASceneGraph::createFormation9()
{
    AFormation* newFormation = AFormationFactory::createFormation9();

    return createFormation(newFormation);
}

//==============================================================================

AFormation* ASceneGraph::createFormation10()
{
    AFormation* newFormation = AFormationFactory::createFormation10();

    return createFormation(newFormation);
}

//==============================================================================

AFormation* ASceneGraph::createRandomFormation()
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

void ASceneGraph::assignCurrentFormation(AFormation* formation)
{
    _currentFormation = createFormation(formation);
}

//==============================================================================

void ASceneGraph::replaceCurrentFormation(AFormation* formation)
{
    deleteFormation(_currentFormation);
    _currentFormation = createFormation(formation);
}

//==============================================================================

AFormation* ASceneGraph::currentFormation()
{
    return _currentFormation;
}

//==============================================================================

#pragma mark - Well formation -

//==============================================================================

AFormation* ASceneGraph::createWellFormation(const TFloat width, const TFloat height, const TFloat depth)
{
    deleteFormation(_wellFormation);
    AFormation* newFormation = AFormationFactory::createFormation(width, height, depth);
    _wellFormation = createFormation(newFormation);
    
    return _wellFormation;
}

//==============================================================================

AFormation* ASceneGraph::wellFormation()
{
    return _wellFormation;
}

//==============================================================================

TFloat ASceneGraph::wellWidth()
{
    return _wellFormation->width();
}

//==============================================================================

TFloat ASceneGraph::wellHeight()
{
    return _wellFormation->height();
}

//==============================================================================

TFloat ASceneGraph::wellDepth()
{
    return _wellFormation->levelsCount();
}

//==============================================================================

#pragma mark - Drop logic -

//==============================================================================

void ASceneGraph::dropCurrentFormation()
{
    makeFormationDropped(_currentFormation);
    assignCurrentFormation(createRandomFormation());
}

//==============================================================================

const TFormationList& ASceneGraph::droppedFormationsList()
{
    return _droppedFormationsList;
}

//==============================================================================

#pragma mark - Routine -

//==============================================================================

AFormation* ASceneGraph::createFormation(AFormation *formation)
{
    return pushFormation(formation);
}

//==============================================================================

AFormation* ASceneGraph::pushFormation(AFormation* pushFormation)
{
    _formationList.push_back(pushFormation);

    return _formationList.back();
}

//==============================================================================

void ASceneGraph::destroyAllFormations()
{
    for (TFormationListIter iter = _formationList.begin(); iter != _formationList.end(); iter++)
    {
        AFormation *formation = *iter;
        deleteFormation(formation);
    }
}

//==============================================================================

void ASceneGraph::deleteFormation(AFormation* formation)
{
    if (formation == 0)
        return;
    
    _formationList.remove(formation);
    delete formation;
}

//==============================================================================

void ASceneGraph::makeFormationDropped(AFormation *formation)
{
    if (formation == 0)
        return;

    _droppedFormationsList.push_back(formation);
}

//==============================================================================

}   //  namespace spcTGame
