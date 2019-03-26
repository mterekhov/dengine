#import "AAppDelegate.h"
#import "ARenderView.h"

//==============================================================================

@interface AAppDelegate ()

@property (nonatomic, weak) IBOutlet NSWindow *window;

@end

//==============================================================================

@implementation AAppDelegate

//==============================================================================

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    NSOpenGLPixelFormatAttribute openglPixelFormatAttributes [] = {
        NSOpenGLPFANoRecovery,
        NSOpenGLPFAColorSize, 32,
        NSOpenGLPFADepthSize, 32,
        NSOpenGLPFAMaximumPolicy,
        NSOpenGLPFADoubleBuffer,
        NSOpenGLPFAAccelerated,
        0
    };
    NSOpenGLPixelFormat* openglPixelFormat = [[NSOpenGLPixelFormat alloc] initWithAttributes: openglPixelFormatAttributes];
    ARenderView* openglView = [[ARenderView alloc] initWithFrame: self.window.frame
                                                     pixelFormat: openglPixelFormat];

    self.window.contentView = openglView;
    [self.window makeFirstResponder: openglView];
}

//==============================================================================

@end
