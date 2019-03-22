#import <Foundation/Foundation.h>

#include "amacbundle.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

TString AMacBundle::fullPathToResource(const TString& resourceFileName)
{
    NSBundle *mainBundle = [NSBundle mainBundle];
    NSString *resourceNSFileName = [NSString stringWithUTF8String:resourceFileName.c_str()];
    NSString *fullNSPathToResource = [mainBundle pathForResource:resourceNSFileName ofType:nil];
    
    return [fullNSPathToResource UTF8String];
}

//==============================================================================

}   //  namespace spcTGame
