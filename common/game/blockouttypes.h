#ifndef SPCTGAME_BLOCKOUTTYPES_H
#define SPCTGAME_BLOCKOUTTYPES_H

//==============================================================================

#if defined(__APPLE__)
    # include "TargetConditionals.h"
    # if defined(TARGET_IPHONE_SIMULATOR) && (TARGET_IPHONE_SIMULATOR != 0)
        #define APPLE_IPHONE_SIMULATOR 1
    # elif defined(TARGET_OS_IPHONE) && (TARGET_OS_IPHONE != 0)
        #define APPLE_IPHONE_DEVICE 1
    # elif defined(TARGET_OS_MAC)
        #define APPLE_MACOSX 1
    # endif
#endif /* Apple */

#include <math.h>
#include <string>

#include "aopengl.h"

//==============================================================================

#define FLOAT_PRECISION 0.000001f
#define DEG_TO_RAD(deg)	((deg) * M_PI / 180.0f)
#define RAD_TO_DEG(rad) ((rad) * 180.0f / M_PI)

//==============================================================================

namespace spcTGame
{

//==============================================================================

typedef GLuint TUint;
typedef GLint TInt;
typedef GLubyte TData;
typedef GLushort TUShort;
typedef GLfloat TFloat;
typedef GLenum TEnum;
typedef GLsizei TSize;
typedef GLvoid TVoid;
typedef GLbitfield TBitfield;

typedef TUint TWidth;
typedef TUint THeight;
typedef TUint TBytepp;
typedef TUint TBitpp;
typedef bool TBool;
typedef std::string TString;

//==============================================================================
    
}   //  namespace spcTGame
    
//==============================================================================

#endif  //  SPCTGAME_BLOCKOUTTYPES_H
