#ifndef SPCTGAME_AIMAGE_H
#define SPCTGAME_AIMAGE_H

//=============================================================================

#include "blockouttypes.h"

#include <string>

//=============================================================================

namespace spcTGame
{
    
//==============================================================================
    
/**
    @class AImage
    image class
*/
class AImage
{
public:
    /// This constructor copies all the data from pointer data to it's own pointer
    AImage(const TString& imageName, TData* data, const TWidth width,
            const THeight height, const TBitpp bitpp);
    
    /// default destructor
    virtual ~AImage();
    
    /// Get data container for image data
    /// @return const ASRAM* - pointer to data. Does not change class object
    const TData* data() const;
    
    /// Get image width
    /// @return const TWidth - width of image. Does not change class object
    const TWidth width() const;

    /// Get image height
    /// @return const THeight - height of image. Does not change class object
    const THeight height() const;

    /// Get image byte per pixel
    /// @return const TBytepp - byte per pixel. Does not change class object
    const TBytepp bytePerPixel() const;

    /// Get image bit per pixel
    /// @return const TBitpp - bit per pixel. Does not change class object
    const TBitpp bitPerPixel() const;

    /// Get image name
    /// @return const TString& - image name. Does not change class object
    const TString& name() const;
    
protected:
    /// Smart pointer to image data container
    TData* _pData;
    
    /// Image width
    TWidth _width;
    
    /// Image height
    THeight _height;
    
    /// Image bytes per pixel
    TBytepp _bytePerPixel;
    
    /// Image bit per pixel
    TBitpp _bitPerPixel;
    
    /// Image name
    TString _name;
};

//=============================================================================

}   //  namespace spcTGame
    
//==============================================================================
    
#endif  //  SPCTGAME_AIMAGE_H
