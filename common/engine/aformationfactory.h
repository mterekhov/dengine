#ifndef SPCTGAME_AFORMATIONFACTORY_H
#define SPCTGAME_AFORMATIONFACTORY_H

//==============================================================================
//
//  This class is just creating formations and not storing it
//  It allocates memory and do not free it!!!!! You should do it manualy
//
//==============================================================================

#include "aformation.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
enum EFormation
{
    FORMATIONS_ONE,
    FORMATIONS_TWO,
    FORMATIONS_THREE,
    FORMATIONS_FOUR,
    FORMATIONS_FIVE,
    FORMATIONS_SIX,
    FORMATIONS_SEVEN,
    FORMATIONS_EIGHT,
    FORMATIONS_COUNT
};

//==============================================================================

class AFormationFactory
{
public:
    static AFormation* createFormation(const TUint column, const TUint row, const TUint levelIndex);
    static AFormation* createFormation1();
    static AFormation* createFormation2();
    static AFormation* createFormation3();
    static AFormation* createFormation4();
    static AFormation* createFormation5();
    static AFormation* createFormation6();
    static AFormation* createFormation7();
    static AFormation* createFormation8();
    static AFormation* createFormation9();
    static AFormation* createFormation10();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AFORMATIONFACTORY_H
