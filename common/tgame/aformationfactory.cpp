#include "aformationfactory.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

AFormation* AFormationFactory::createFormation1()
{
    AFormation* formation = AFormationFactory::createFormation(1, 1, 1);
    if (formation->item(0, 0, 0, EDATASTATE_RENDERABLE) == false)
        return 0;

    return formation;
}

//==============================================================================

AFormation* AFormationFactory::createFormation2()
{
    AFormation* formation = AFormationFactory::createFormation(1, 2, 1);
    if (formation->item(0, 0, 0, EDATASTATE_RENDERABLE) == false)
        return 0;

    if (formation->item(0, 1, 0, EDATASTATE_RENDERABLE) == false)
        return 0;

    return formation;
}

//==============================================================================

AFormation* AFormationFactory::createFormation3()
{
    AFormation* formation = AFormationFactory::createFormation(1, 3, 1);
    if (formation->item(0, 0, 0, EDATASTATE_RENDERABLE) == false)
        return 0;

    if (formation->item(0, 1, 0, EDATASTATE_RENDERABLE) == false)
        return 0;

    if (formation->item(0, 2, 0, EDATASTATE_RENDERABLE) == false)
        return 0;

    return formation;
}

//==============================================================================

AFormation* AFormationFactory::createFormation4()
{
    AFormation* formation = AFormationFactory::createFormation(2, 2, 1);
    if (formation->item(0, 0, 0, EDATASTATE_RENDERABLE) == false)
        return 0;

    if (formation->item(1, 0, 0, EDATASTATE_RENDERABLE) == false)
        return 0;

    if (formation->item(0, 1, 0, EDATASTATE_RENDERABLE) == false)
        return 0;

    return formation;
}

//==============================================================================

AFormation* AFormationFactory::createFormation5()
{
    AFormation* formation = AFormationFactory::createFormation(2, 2, 1);
    if (formation->item(0, 0, 0, EDATASTATE_RENDERABLE) == false)
        return 0;

    if (formation->item(1, 1, 0, EDATASTATE_RENDERABLE) == false)
        return 0;

    if (formation->item(0, 1, 0, EDATASTATE_RENDERABLE) == false)
        return 0;

    if (formation->item(1, 0, 0, EDATASTATE_RENDERABLE) == false)
        return 0;

    return formation;
}

//==============================================================================

AFormation* AFormationFactory::createFormation6()
{
    AFormation* formation = AFormationFactory::createFormation(2, 3, 1);
    if (formation->item(0, 0, 0, EDATASTATE_RENDERABLE) == false)
        return 0;

    if (formation->item(0, 1, 0, EDATASTATE_RENDERABLE) == false)
        return 0;

    if (formation->item(0, 2, 0, EDATASTATE_RENDERABLE) == false)
        return 0;

    if (formation->item(1, 1, 0, EDATASTATE_RENDERABLE) == false)
        return 0;

    return formation;
}

//==============================================================================

AFormation* AFormationFactory::createFormation7()
{
    AFormation* formation = AFormationFactory::createFormation(3, 2, 1);
    if (formation->item(0, 0, 0, EDATASTATE_RENDERABLE) == false)
        return 0;
    
    if (formation->item(1, 0, 0, EDATASTATE_RENDERABLE) == false)
        return 0;
    
    if (formation->item(1, 1, 0, EDATASTATE_RENDERABLE) == false)
        return 0;
    
    if (formation->item(2, 1, 0, EDATASTATE_RENDERABLE) == false)
        return 0;

    return formation;
}

//==============================================================================

AFormation* AFormationFactory::createFormation8()
{
    AFormation* formation = AFormationFactory::createFormation(2, 3, 1);
    if (formation->item(0, 0, 0, EDATASTATE_RENDERABLE) == false)
        return 0;
    
    if (formation->item(0, 1, 0, EDATASTATE_RENDERABLE) == false)
        return 0;
    
    if (formation->item(0, 2, 0, EDATASTATE_RENDERABLE) == false)
        return 0;
    
    if (formation->item(1, 2, 0, EDATASTATE_RENDERABLE) == false)
        return 0;

    return formation;
}

//==============================================================================

AFormation* AFormationFactory::createFormation9()
{
    return new AFormation();
}

//==============================================================================

AFormation* AFormationFactory::createFormation10()
{
    return new AFormation();
}

//==============================================================================

AFormation* AFormationFactory::createFormation(const TUint column, const TUint row, const TUint levelIndex)
{
    AFormation* newFormation = new AFormation(column, row, levelIndex);
    return newFormation;
}
    
//==============================================================================
    
}   //  namespace spcTGame
