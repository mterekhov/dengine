#include "atexturemanager.h"
#include "atga.h"
#include "aopenglstate.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================
    
ATexture ATextureManager::_zeroTexture;

//==============================================================================

ATexture& ATextureManager::zeroTexture()
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

ATexture& ATextureManager::createTextureFromData(const AImage& image)
{
    AOpenGLState* oglState = AOpenGLState::shared();
    oglState->textureEnable();
    
    ATexture newTexture(image);
    _textureList[newTexture.name()] = newTexture;
    
    oglState->textureDisable();
    return _textureList[newTexture.name()];
}

    
//==============================================================================

ATexture& ATextureManager::createTextureFromTGA(const TString& filePath)
{
    ATga tgaFile(filePath);
    return createTextureFromData(tgaFile.image());
}

//==============================================================================

ATexture& ATextureManager::createOrFindTexture(const AImage& image)
{
    TTexturesListIter textureIter = _textureList.find(image.name());
    if (textureIter == _textureList.end())
        return createTextureFromData(image);
    
    return textureIter->second;
}
    
//==============================================================================

ATexture& ATextureManager::createOrFindTextureFromTGA(const TString& filePath)
{
    TTexturesListIter textureIter = _textureList.find(filePath);
    if (textureIter == _textureList.end())
        return createTextureFromTGA(filePath);
    
    return textureIter->second;
}

//==============================================================================
    
}   //  namespace spcTGame
