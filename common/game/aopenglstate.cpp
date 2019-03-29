#include "aopenglstate.h"
#include "blockoutdebug.h"
#include "atexturemanager.h"
#include "aoglwrapper.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
AOpenGLState* AOpenGLState::instance = 0;

//==============================================================================

#pragma mark - Init -

//==============================================================================

void AOpenGLState::create()
{
    AOpenGLState::shared();
}

//==============================================================================

AOpenGLState* AOpenGLState::shared()
{
    if (instance)
        return instance;
    
    instance = new AOpenGLState();
    return instance;
}

//==============================================================================

AOpenGLState::AOpenGLState() : _lineWidth(1.0f), _textureEnabled(false), _currentTexture(ATextureManager::zeroTexture()), _drawColor(AColor::whiteColor())
{
    drawColorSetup(_drawColor);
    clearColorSetup(_clearColor);

    AOGLWrapper::oglEnable(GL_DEPTH_TEST);
    AOGLWrapper::oglClearDepth(1.0f);
    AOGLWrapper::oglDepthFunc(GL_LESS);

    AOGLWrapper::oglEnable(GL_CULL_FACE); 
	AOGLWrapper::oglShadeModel(GL_SMOOTH); // Type of shading for the polygons
    AOGLWrapper::oglEnableClientState(GL_VERTEX_ARRAY);
}

//==============================================================================

AOpenGLState::~AOpenGLState()
{
}

//==============================================================================

#pragma mark - Colors -

//==============================================================================

AColor AOpenGLState::clearColor() const
{
    return _clearColor;
}

//==============================================================================

void AOpenGLState::clearColor(const AColor& color)
{
    _clearColor = color;
    clearColorSetup(color);
}

//==============================================================================

AColor AOpenGLState::drawColor() const
{
    return _drawColor;
}

//==============================================================================

void AOpenGLState::drawColor(const AColor& color)
{
    _drawColor = color;
    drawColorSetup(color);
}

//==============================================================================

#pragma mark - OpenGL calls -

//==============================================================================

void AOpenGLState::drawColorSetup(const AColor& color)
{
    AOGLWrapper::oglColor4f(color.red, color.green, color.blue, color.alpha);
}

//==============================================================================

void AOpenGLState::clearColorSetup(const AColor& color)
{
    AOGLWrapper::oglClearColor(color.red, color.green, color.blue, color.alpha);
}

//==============================================================================

void AOpenGLState::frustumSetup(const TFloat screenWidth, const TFloat screenHeight)
{
    AOGLWrapper::oglViewport(0.0f, 0.0f, screenWidth, screenHeight);
    
    TFloat aspect = screenWidth / screenHeight;
    TFloat near = 0.1f;
    TFloat far = 10000.0f;
    TFloat fieldOfView = 45.0f;
    TFloat size = near * tanf(DEG_TO_RAD(fieldOfView) / 2.0f);
    TFloat width = size;
    TFloat height = size / aspect;
    
    AOGLWrapper::oglMatrixMode(GL_PROJECTION);
    AOGLWrapper::oglLoadIdentity();
    AOGLWrapper::oglFrustum(-width, width, -height, height, near, far);
    
    AOGLWrapper::oglMatrixMode(GL_MODELVIEW);
    AOGLWrapper::oglLoadIdentity();
}

//==============================================================================

void AOpenGLState::pushMarices()
{
    AOGLWrapper::oglPushMatrix();
}

//==============================================================================

void AOpenGLState::popMarices()
{
    AOGLWrapper::oglPopMatrix();
}

//==============================================================================

void AOpenGLState::translate(const APoint& point)
{
    AOGLWrapper::oglTranslatef(point.x, point.y, point.z);
}

//==============================================================================

void AOpenGLState::textureEnable()
{
    if (_textureEnabled)
    {
        loger("textures already enabled");
        return;
    }
    
    _textureEnabled = true;
    AOGLWrapper::oglEnable(GL_TEXTURE_2D);
    AOGLWrapper::oglEnableClientState(GL_TEXTURE_COORD_ARRAY);
}

//==============================================================================

void AOpenGLState::textureDisable()
{
    if (!_textureEnabled)
    {
        loger("textures already disabled");
        return;
    }
    
    _textureEnabled = false;
    AOGLWrapper::oglDisable(GL_TEXTURE_2D);
    AOGLWrapper::oglDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

//==============================================================================

TBool AOpenGLState::textureEnabled() const
{
    return _textureEnabled;
}

//==============================================================================

TBool AOpenGLState::currentTexture(const ATexture& texture)
{
    if (_textureEnabled == false)
        return false;

    _currentTexture = texture;
    texture.bind();

    return true;
}

//==============================================================================

const ATexture& AOpenGLState::currentTexture() const
{
    return _currentTexture;
}

//==============================================================================

void AOpenGLState::clearCurrentTexture()
{
    _currentTexture.unBind();
    _currentTexture = ATextureManager::zeroTexture();
}

//==============================================================================

void AOpenGLState::clear(GLbitfield mask)
{
    AOGLWrapper::oglClear(mask);
}

//==============================================================================

TFloat AOpenGLState::lineWidth() const
{
    return _lineWidth;
}

//==============================================================================

void AOpenGLState::lineWidth(const TFloat width)
{
    _lineWidth = width;
    AOGLWrapper::oglLineWidth(width);
}

//==============================================================================

TString AOpenGLState::lastError()
{
    TString error = "unknown error";
    
    TEnum errorCode = AOGLWrapper::oglGetError();
    switch (errorCode) {
        case GL_NO_ERROR:
            error = "ok";
            break;
        case GL_INVALID_ENUM:
            error = "An unacceptable value is specified for an enumerated argument. The offending command is ignored, and has no other side effect than to set the error flag.";
            break;
        case GL_INVALID_VALUE:
            error = "A numeric argument is out of range. The offending command is ignored, and has no other side effect than to set the error flag.";
            break;
        case GL_INVALID_OPERATION:
            error = "The specified operation is not allowed in the current state. The offending command is ignored, and has no other side effect than to set the error flag.";
            break;
        case GL_STACK_OVERFLOW:
            error = "This command would cause a stack overflow. The offending command is ignored, and has no other side effect than to set the error flag.";
            break;
        case GL_STACK_UNDERFLOW:
            error = "This command would cause a stack underflow. The offending command is ignored, and has no other side effect than to set the error flag.";
            break;
        case GL_OUT_OF_MEMORY:
            error = "There is not enough memory left to execute the command. The state of the GL is undefined, except for the state of the error flags, after this error is recorded.";
            break;
    }
    
    return error;
}
    
//==============================================================================
    
}   //  namespace spcTGame
