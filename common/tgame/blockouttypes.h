#ifndef SPCTGAME_BLOCKOUTTYPES_H
#define SPCTGAME_BLOCKOUTTYPES_H

//==============================================================================

#include <OpenGL/gl.h>
#include <math.h>
#import <string>

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
typedef GLdouble TDouble;
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
