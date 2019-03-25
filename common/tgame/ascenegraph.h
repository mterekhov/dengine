#ifndef SPCTGAME_ADATASTORAGE_H
#define SPCTGAME_ADATASTORAGE_H

//==============================================================================
//
//  This class is responsible for creating and storing formations of any kind
//  Also it is instance provided as a reference to all the members of application
//  you need.
//
//==============================================================================

#include <list>

#include "aformationfactory.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

typedef std::list<AFormation*> TFormationList;
typedef TFormationList::iterator TFormationListIter;
typedef TFormationList::const_iterator TFormationListConstIter;

//==============================================================================

class ASceneGraph
{
private:
    //  list of all formations. It shouldn't be used for rendering!!!!
    //  It is memory managment only
    TFormationList _formationList;

    //  current block formation
    AFormation* _currentFormation;

    //  well formation just to define well sizes WIDTHxHEIGHTxDEPTH
    AFormation* _wellFormation;

    //  list of all formations for dropped blocks
    TFormationList _droppedFormationsList;

    //  push formation into _formationList
    AFormation* createFormation(AFormation *formation);
    
    //  delete formation from _formationList and destroy as object(call delete)
    void deleteFormation(AFormation* formation);
    
    //  Push formation into _formationList
    AFormation* pushFormation(AFormation* pushFormation);

    //  clear _formationList
    void destroyAllFormations();

    void makeFormationDropped(AFormation *formation);

public:
    static TFloat cellSize();

    ASceneGraph();
    ~ASceneGraph();
    
    //  These methods create formations
    //  push it into _formationList and returns the created one
    AFormation* createFormation1();
    AFormation* createFormation2();
    AFormation* createFormation3();
    AFormation* createFormation4();
    AFormation* createFormation5();
    AFormation* createFormation6();
    AFormation* createFormation7();
    AFormation* createFormation8();
    AFormation* createFormation9();
    AFormation* createFormation10();
    AFormation* createRandomFormation();

    //  destroys current formation completely with deleteFormation() call
    //  assignes new one with createFormation(...) call
    void replaceCurrentFormation(AFormation* formation);
    
    //  assigns new value to _currentFormation
    //  and NOT removes it from _formationsList
    void assignCurrentFormation(AFormation* formation);
    
    //  returns current formation
    AFormation* currentFormation();
    
    //  creates well formation with createFormation()
    //  and assignes it to _wellFormation
    AFormation* createWellFormation(const TFloat width, const TFloat height, const TFloat depth);
    
    //  _wellFormation getter
    AFormation* wellFormation();

    //  _wellFormation width
    TFloat wellWidth();

    //  _wellFormation height
    TFloat wellHeight();

    //  _wellFormation depth
    TFloat wellDepth();

    const TFormationList& droppedFormationsList();
    
    void dropCurrentFormation();
};

//==============================================================================
    
}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ADATASTORAGE_H
