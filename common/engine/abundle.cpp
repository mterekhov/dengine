#include "abundle.h"
#include "amacbundle.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

ABundle::ABundle()
{
    _bundle = new AMacBundle();
}

//==============================================================================

ABundle::~ABundle()
{
    if (_bundle)
        delete _bundle;
}

//==============================================================================

TString ABundle::fullPathToResource(const TString& resourceFileName)
{
    if (!_bundle)
        return "";
    
    if (resourceFileName.length() == 0)
        return "";
    
    return _bundle->fullPathToResource(resourceFileName);
}

//==============================================================================

}   //  namespace spcTGame
