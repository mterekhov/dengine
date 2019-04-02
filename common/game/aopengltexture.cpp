#include "aopengltexture.h"
#include "aopenglstate.h"
#include "atga.h"
#include "aoglwrapper.h"

//=============================================================================

namespace spcTGame
{
    
//==============================================================================
    
AOpenGLTexture::AOpenGLTexture() : _id(0), _type(GL_RGBA), _minFilter(GL_LINEAR), _magFilter(GL_LINEAR),
                       _pixelSize(GL_UNSIGNED_BYTE), _width(0), _height(0), _repeat(true),
                       _mipMaping(false), _name("undefined"), _imageWidth(0), _imageHeight(0)
{
}

//=============================================================================

AOpenGLTexture::AOpenGLTexture(const AOpenGLTexture& tex) : _id(tex._id), _type(tex._type), _minFilter(tex._minFilter),
                                        _magFilter(tex._magFilter), _pixelSize(tex._pixelSize),
                                        _width(tex._width), _height(tex._height), _repeat(tex._repeat),
                                        _mipMaping(tex._mipMaping), _name(tex._name), _imageWidth(tex._imageWidth),
                                        _imageHeight(tex._imageHeight)
{
}

//=============================================================================

AOpenGLTexture::AOpenGLTexture(const AImage& image) : _id(0), _type(GL_RGBA), _minFilter(GL_LINEAR), _magFilter(GL_LINEAR),
                       _pixelSize(GL_UNSIGNED_BYTE), _width(0), _height(0), _repeat(true),
                       _mipMaping(false), _name("undefined"), _imageWidth(0), _imageHeight(0)
{
    AOGLWrapper::oglGenTextures(1, &_id);
    init(image);
}

//=============================================================================

AOpenGLTexture::~AOpenGLTexture()
{
}

//=============================================================================

void AOpenGLTexture::destroy()
{
    if (_id)
    {
        AOGLWrapper::oglDeleteTextures(1, &_id);
        _id = 0;
    }
}

//=============================================================================

void AOpenGLTexture::defineImageType(const int bytePP)
{
    switch (bytePP)
    {
        case 3:
            _type = GL_RGB;
        break;
        
        case 4:
            _type = GL_RGBA;
        break;
        
    }
}

//=============================================================================

TBool AOpenGLTexture::init(const AImage& image)
{
    defineImageType(image.bytePerPixel());
    
    //  extend image data up to nearest power of two
    locateSize(image.width(), image.height());
    bind();
    defineFilters();
    _name = image.name();

    if ((_width != image.width()) || (_height != image.height()))
    {
        TData* data = new TData[_width * _height * image.bytePerPixel()];
        correctData(image, data);
        AOGLWrapper::oglTexImage2D(GL_TEXTURE_2D, 0, _type, _width, _height, 0, _type, _pixelSize, data);
        delete [] data;
    }
    else
    {
        const TData* data = image.data();
        AOGLWrapper::oglTexImage2D(GL_TEXTURE_2D, 0, _type, _width, _height, 0, _type, _pixelSize, data);
    }
        
    return true;
}

//=============================================================================

void AOpenGLTexture::defineFilters()
{
    if (!_repeat)
    {
        AOGLWrapper::oglTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        AOGLWrapper::oglTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    }
    else
    {
        AOGLWrapper::oglTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        AOGLWrapper::oglTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }

//  This parameter is deprecated but should be used in version lower then OpenGL 3.0
//  in all upper versions should be used glGenerateMipmap​().
//    AOGLWrapper::oglTexParameterf(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, _mipMaping);
    AOGLWrapper::oglTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _minFilter);
    AOGLWrapper::oglTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _magFilter);
}
    
//=============================================================================

void AOpenGLTexture::locateSize(const TWidth width, const THeight height)
{
    THeight correctHeight = 1;
    TWidth correctWidth = 1;
    while(true)
    {
        if (correctHeight >= height)
            break;
        correctHeight = correctHeight << 1;
    };
    while(true)
    {
        if (correctWidth >= width)
            break;
        correctWidth = correctWidth << 1;
    };
    
    _imageWidth = width;
    _imageHeight = height;
    
    _height = correctHeight;
    _width = correctWidth;
}

//=============================================================================

void AOpenGLTexture::bind() const
{
    printf("binding <%i>\n", _id);
    AOGLWrapper::oglBindTexture(GL_TEXTURE_2D, _id);
}

//=============================================================================

void AOpenGLTexture::unBind() const
{
    AOGLWrapper::oglBindTexture(GL_TEXTURE_2D, 0);
}

//=============================================================================

const TWidth AOpenGLTexture::imageWidth() const
{
    return _imageWidth;
}

//=============================================================================

const THeight AOpenGLTexture::imageHeight() const
{
    return _imageHeight;
}
    
//=============================================================================

const TWidth AOpenGLTexture::width() const
{
    return _width;
}

//=============================================================================

const THeight AOpenGLTexture::height() const
{
    return _height;
}
    
//=============================================================================

void AOpenGLTexture::correctData(const AImage& image, TData* data)
{
    const TData* originalData = image.data();
    TUShort bytepp = image.bytePerPixel();
    
    for (TUint i = 0; i < _height; i++)
    {
        for (TUint j = 0; j < _width; j++)
        {
            TUint index = bytepp * (_width * i + j);
            if ((j >= _imageWidth) || (i >= _imageHeight))
            {
                memset(&data[index], 0, bytepp);
            }
            else
            {
                TUint index2 = bytepp * (_imageWidth * i + j);
                memcpy(&data[index], &originalData[index2], bytepp);
            }
        }
    }
}

//=============================================================================

const GLenum AOpenGLTexture::type() const
{
    return _type;
}

//=============================================================================

const TString& AOpenGLTexture::name() const
{
    return _name;
}

//=============================================================================

void AOpenGLTexture::minFilter(const GLuint min)
{
    _minFilter = min;
}

//=============================================================================

void AOpenGLTexture::magFilter(const GLuint mag)
{
    _magFilter = mag;
}

//=============================================================================

void AOpenGLTexture::repeat(const TBool r)
{
    _repeat = r;
}

//=============================================================================

void AOpenGLTexture::mipMapping(const TBool m)
{
    _mipMaping = m;
}

//=============================================================================

void AOpenGLTexture::name(const TString& name)
{
    _name = name;
}

//==============================================================================
    
}   //  namespace spcTGame
