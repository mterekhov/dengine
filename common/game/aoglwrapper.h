#ifndef SPCTGAME_AOGLWRAPPER_H
#define SPCTGAME_AOGLWRAPPER_H

//==============================================================================

#include "blockouttypes.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

class AOGLWrapper
{
public:
    static void oglDrawArrays(TEnum mode, TInt first, TSize count);
    static void oglTranslatef(TFloat x, TFloat y, TFloat z);
    static void oglEnable(TEnum cap);
    static void oglClearColor(TFloat red, TFloat green, TFloat blue, TFloat alpha);
    static void oglViewport(TInt x, TInt y, TSize width, TSize height);
    static void oglDisable(TEnum cap);
    static void oglClear(TBitfield mask);
    static void oglLineWidth(TFloat width);
    static void oglGenTextures(TSize n, TUint* textures);
    static void oglDeleteTextures(TSize n, const TUint* textures);
    static void oglTexImage2D(TEnum target, TInt level, TInt internalformat, TSize width, TSize height, TInt border, TEnum format, TEnum type, const TVoid* pixels);
    static void oglTexParameterf(TEnum target, TEnum pname, TFloat param);
    static void oglBindTexture(TEnum target, TUint texture);
    static TEnum oglGetError();
    static void oglBlendFunc();
    static void oglDepthFunc(TEnum func);

    static void oglFrustum(TFloat left, TFloat right, TFloat bottom, TFloat top, TFloat zNear, TFloat zFar);
    static void oglPushMatrix();
    static void oglMatrixMode(TEnum mode);
    static void oglLoadIdentity();
    static void oglClearDepth(TFloat depth);
    static void oglShadeModel(TEnum mode);
    static void oglEnableClientState(TEnum array);
    static void oglColor4f(TFloat red, TFloat green, TFloat blue, TFloat alpha);
    static void oglMultMatrixf(const TFloat* m);
    static void oglDisableClientState(TEnum array);
    static void oglPopMatrix();
    static void oglTexCoordPointer(TInt size, TEnum type, TSize stride, const TVoid* pointer);
    static void oglVertexPointer(TInt size, TEnum type, TSize stride, const TVoid* pointer);
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_AOGLWRAPPER_H
