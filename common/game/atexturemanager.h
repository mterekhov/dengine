#ifndef SPCTGAME_ATEXTUREMANAGER_H
#define SPCTGAME_ATEXTUREMANAGER_H

//==============================================================================

#include <map>
#include <string>

#include "aopengltexture.h"
#include "aimagedata.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
typedef std::map<TString, AOpenGLTexture> TTexturesList;
typedef TTexturesList::iterator TTexturesListIter;
typedef TTexturesList::const_iterator TTexturesListConstIter;

//==============================================================================

class ATextureManager
{
private:
    AOpenGLTexture& createTextureFromData(const AImage& image);
    
    TTexturesList _textureList;
    static AOpenGLTexture _zeroTexture;

public:
    static AOpenGLTexture& zeroTexture();

    ATextureManager();
    ~ATextureManager();
    
    AOpenGLTexture& createOrFindTexture(const std::string& textureName, const spcWAD::AImageData& wadImageData);
    AOpenGLTexture& createOrFindTexture(const AImage& image);
    AOpenGLTexture& createOrFindTextureFromTGA(const TString& filePath);
    AOpenGLTexture& createTextureFromTGA(const TString& filePath);
};

//==============================================================================

}   //  namespace spcTGame
    
//==============================================================================
    
#endif  //  SPCTGAME_ATEXTUREMANAGER_H
