#include "atexturemanager.h"
#include "atga.h"
#include "aopenglstate.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
AOpenGLTexture ATextureManager::_zeroTexture;

//==============================================================================

AOpenGLTexture& ATextureManager::zeroTexture()
{
    return _zeroTexture;
}

//==============================================================================

ATextureManager::ATextureManager()
{
}

//==============================================================================

ATextureManager::~ATextureManager()
{
}

//==============================================================================

AOpenGLTexture& ATextureManager::createTextureFromData(const AImage& image)
{
    AOpenGLState* oglState = AOpenGLState::shared();
    oglState->textureEnable();
    
    AOpenGLTexture newTexture(image);
    _textureList[newTexture.name()] = newTexture;
    
    oglState->textureDisable();
    return _textureList[newTexture.name()];
}

    
//==============================================================================

AOpenGLTexture& ATextureManager::createTextureFromTGA(const TString& filePath)
{
    ATga tgaFile(filePath);
    return createTextureFromData(tgaFile.image());
}

//==============================================================================

AOpenGLTexture& ATextureManager::createOrFindTexture(const AImage& image)
{
    TTexturesListIter textureIter = _textureList.find(image.name());
    if (textureIter == _textureList.end())
        return createTextureFromData(image);
    
    return textureIter->second;
}
    
//==============================================================================

AOpenGLTexture& ATextureManager::createOrFindTextureFromTGA(const TString& filePath)
{
    TTexturesListIter textureIter = _textureList.find(filePath);
    if (textureIter == _textureList.end())
        return createTextureFromTGA(filePath);
    
    return textureIter->second;
}

//==============================================================================
    
AOpenGLTexture& ATextureManager::createOrFindTexture(const std::string& textureName, const spcWAD::AImageData& wadImageData)
{
    TTexturesListIter textureIter = _textureList.find(textureName);
    if (textureIter == _textureList.end())
    {
        AImage gameImage(textureName, wadImageData.data(), wadImageData.width(), wadImageData.height(), 32);
        return createTextureFromData(gameImage);
    }
        
        return textureIter->second;
}

}   //  namespace spcTGame
