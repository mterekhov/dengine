#ifndef SPCTGAME_AOPENGLSTATE_H
#define SPCTGAME_AOPENGLSTATE_H

//==============================================================================

#include "acolor.h"
#include "atexture.h"
#include "apoint.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
class AOpenGLState
{
private:
    static AOpenGLState* instance;
    
    ATexture _currentTexture;
    AColor _clearColor;
    AColor _drawColor;
    TFloat _lineWidth;
    TBool _textureEnabled;
    
    void clearColorSetup(const AColor& color);
    void drawColorSetup(const AColor& color);
    
public:
    static void create();
    static AOpenGLState* shared();
    
    AOpenGLState();
    ~AOpenGLState();
    
    TFloat lineWidth() const;
    void lineWidth(const TFloat width);
    
    AColor clearColor() const;
    void clearColor(const AColor& color);
    
    AColor drawColor() const;
    void drawColor(const AColor& color);

    void frustumSetup(const TFloat screenWidth, const TFloat screenHeight);
    
    void pushMarices();
    void popMarices();
    
    void translate(const APoint& point);
    
    void textureEnable();
    void textureDisable();
    TBool textureEnabled() const;
    
    void clear(GLbitfield mask);
    
    TBool currentTexture(const ATexture& texture);
    const ATexture& currentTexture() const;
    void clearCurrentTexture();
    
    TString lastError();
};

//==============================================================================

}   //  namespace spcTGame
    
//==============================================================================
    
#endif  //  SPCTGAME_AOPENGLSTATE_H
