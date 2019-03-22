#ifndef SPCTGAME_AFORMATION_H
#define SPCTGAME_AFORMATION_H

//==============================================================================
//
//  This class is a simple formation
//
//==============================================================================

#include "blockouttypes.h"
#include "apoint.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
enum EDataState
{
    EDATASTATE_EMPTY,
    EDATASTATE_RENDERABLE,
    EDATASTATE_ROTATED
};

//==============================================================================

class AFormation
{
private:
    TUint _width;   //  is mapped to z axis of ogl
    TUint _height;  //  is mapped to x axis of ogl
    TUint _levelsCount; //  is mapped to y axis of ogl
    TData* _data;
    APoint _gridSpacePosition;

public:
    AFormation();
    AFormation(const TUint width, const TUint height, const TUint count);
    AFormation(const AFormation& formation);
    ~AFormation();
    
    const TData* data() const;
    TData* data();
    TUint height() const;
    TUint width() const;
    TUint levelsCount() const;
    TData item(const TUint column, const TUint row, const TUint levelIndex) const;
    TBool item(const TUint column, const TUint row, const TUint levelIndex, const TData& value);
    
    APoint gridSpacePosition() const;
    void gridSpacePosition(const APoint& point);
    APoint gridSpaceLocation(const TUint column, const TUint row, const TUint levelIndex) const;
    
    TBool doesInbounds(const AFormation* data);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AFORMATION_H
