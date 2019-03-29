#ifndef SPCTGAME_ATEXTUREMANAGER_H
#define SPCTGAME_ATEXTUREMANAGER_H

//==============================================================================

#include <map>
#include <string>

#include "atexture.h"
#include "aimagedata.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
typedef std::map<TString, ATexture> TTexturesList;
typedef TTexturesList::iterator TTexturesListIter;
typedef TTexturesList::const_iterator TTexturesListConstIter;

//==============================================================================

class ATextureManager
{
private:
    ATexture& createTextureFromData(const AImage& image);
    
    TTexturesList _textureList;
    static ATexture _zeroTexture;

public:
    static ATexture& zeroTexture();

    ATextureManager();
    ~ATextureManager();
    
    ATexture& createOrFindTexture(const std::string& textureName, const spcWAD::AImageData& wadImageData);
    ATexture& createOrFindTexture(const AImage& image);
    ATexture& createOrFindTextureFromTGA(const TString& filePath);
    ATexture& createTextureFromTGA(const TString& filePath);
};

//==============================================================================

}   //  namespace spcTGame
    
//==============================================================================
    
#endif  //  SPCTGAME_ATEXTUREMANAGER_H
