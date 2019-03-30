#ifndef SPCTGAME_AOPENGLTEXTURE_H
#define SPCTGAME_AOPENGLTEXTURE_H

//=============================================================================

#include <string>

#include "aimage.h"

//=============================================================================

namespace spcTGame
{
    
//==============================================================================
    
/**
    @class AOpenGLTexture
    Class for texture holding and all it's attributes
*/
class AOpenGLTexture
{
public:
    /// Default Constructor
    AOpenGLTexture();
    
    AOpenGLTexture(const AOpenGLTexture& tex);

    /// Constructor
    /// @param const AImage& - image for initialization of texture
    AOpenGLTexture(const AImage& image);
    
    /// Default destructor
    ~AOpenGLTexture();
    
    /// Bind texture
    void bind() const;
    
    /// Unbin texture
    void unBind() const;
    
    /// Get image width
    /// @return const TWidth - width of original image from tga file
    const TWidth imageWidth() const;

    /// Get image height
    /// @return const THeight - height of original image from tga file
    const THeight imageHeight() const;

    /// Get texture width
    /// @return const TWidth - width of texture
    const TWidth width() const;

    /// Get texture height
    /// @return const THeight - height of texture
    const THeight height() const;
    
    /// Get type of texture
    /// @return const GLenum - type of texture. Means GL_RGBA, GL_RGB or GL_BGR
    const TUint type() const;
    
    const TString& name() const;

    /// Setup minification filter
    /// @param const TUint - minification filter
    void minFilter(const TUint min);

    /// Setup magnification filter
    /// @param const TUint - magnification filter
    void magFilter(const TUint mag);
    
    /// Setup tile parameter
    /// @param const TBool - should we tile all the surface with this texture
    void repeat(const TBool r);
    
    /// Setup mipmap generation
    /// @param const TBool - should we generate mip map levels for this texture 
    void mipMapping(const TBool m);
    
    /// Setup texture name
    /// @param const TString& - name for the texture
    void name(const TString& name);
    
private:
    
    /// Initialize texture
    /// @param AImage& - init texture with image
    /// @return TBool - true if everything is ok, otherwise false
    TBool init(const AImage& image);
    
    /// Destroy all the data in texture object
    void destroy();
    
    /// Init texture from tga file
    /// @param const TString& - relative file name of tga image
    /// @return TBool - true if everything is ok, otherwise false
    TBool initFromTga(const TString& fileName);
    
    /// Apply all the filter to current texture id
    void defineFilters();
    
    void defineImageType(const int bytePP);
    
    /// Find out the nearest power of 2 size for texture
    /// @param const TWidth - width of original image
    /// @param const THeight - height of original image
    void locateSize(const TWidth width, const THeight height);
    
    /// Correct data due to texture sizes
    /// @param const AImage& - image to correct
    /// @param Tubyte* - pointer where the final data will be stored
    void correctData(const AImage& image, TData* data);

    /// Texture name
    TString _name;
    
    /// Texture id
    TUint _id;
    
    /// Texture type(in case of color scheme)
    TUint _type;
    
    /// Number of bytes per pixel component
    TUint _pixelSize;
    
    /// Texture width
    TWidth _width;             //  texture width(usualy pow of 2)
    
    /// Texture height
    THeight _height;           //  texture height(usualy pow of 2)
    
    /// Original image width
    TWidth _imageWidth;        //  width of source image
    
    /// Original image height
    THeight _imageHeight;      //  height of source image

    /// Minification filter
    TUint _minFilter;
    
    /// Magnification filter
    TUint _magFilter;
    
    /// Tile parameter
    TBool _repeat;
    
    /// Mipmap generation parameter
    TBool _mipMaping;
};

//=============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_AOPENGLTEXTURE_H
