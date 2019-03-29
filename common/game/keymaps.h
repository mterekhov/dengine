#ifndef SPCTGAME_KEYMAPS_H
#define SPCTGAME_KEYMAPS_H

//==============================================================================

#include <map>

#include "blockouttypes.h"

//==============================================================================

namespace spcTGame
{

//==============================================================================

typedef std::map<TString, TUint> TStringMap;
typedef std::map<TString, TUint>::iterator TStringMapIter;

//==============================================================================

enum EKeyCodes
{
    EKEYCODES_UP = 126,
    EKEYCODES_DOWN = 125,
    EKEYCODES_LEFT = 123,
    EKEYCODES_RIGHT = 124,
    EKEYCODES_ROTATE_X = 12,
    EKEYCODES_ROTATE_Y = 13,
    EKEYCODES_ROTATE_Z = 14,
    EKEYCODES_DROP_BLOCK = 49,
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_KEYMAPS_H
