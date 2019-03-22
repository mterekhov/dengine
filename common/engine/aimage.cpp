#include "aimage.h"

//=============================================================================

namespace spcTGame
{
    
//==============================================================================
    
AImage::AImage(const TString& imageName, TData* data, const TWidth width,
            const THeight height, const TBitpp bitpp) : _name(imageName),
                                            _width(width), _height(height),
                                            _bitPerPixel(bitpp), _bytePerPixel(bitpp / 8)
{
    TUint sizer = width * height * bitpp / 8;
    _pData = new TData[sizer];
    memset(_pData, 0, sizer);
    
    memcpy(_pData, data, sizer);
}

//=============================================================================

AImage::~AImage()
{
    delete [] _pData;
}

//=============================================================================

const TData* AImage::data() const
{
    return _pData;
}

//=============================================================================

const TWidth AImage::width() const
{
    return _width;
}

//=============================================================================

const THeight AImage::height() const
{
    return _height;
}

//=============================================================================

const TBytepp AImage::bytePerPixel() const
{
    return _bytePerPixel;
}

//=============================================================================

const TBitpp AImage::bitPerPixel() const
{
    return _bitPerPixel;
}

//=============================================================================

const TString& AImage::name() const
{
    return _name;
}

//=============================================================================

}   //  namespace spcTGame
