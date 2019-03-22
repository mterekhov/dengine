#import "AAppDelegate.h"
#import "ARenderView.h"

//==============================================================================

@interface AAppDelegate ()

@property (assign) IBOutlet NSWindow* window;

@end

//==============================================================================

@implementation AAppDelegate

//==============================================================================

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    NSOpenGLPixelFormatAttribute attrs [] = {
        NSOpenGLPFANoRecovery,
//        NSOpenGLPFAWindow,
        NSOpenGLPFAColorSize, 32,
        NSOpenGLPFADepthSize, 32,
        NSOpenGLPFAMaximumPolicy,
        NSOpenGLPFADoubleBuffer,
        NSOpenGLPFAAccelerated,
        0
    };
    NSOpenGLPixelFormat* pixelFormat = [[NSOpenGLPixelFormat alloc] initWithAttributes: attrs];

    ARenderView* view = [[ARenderView alloc] initWithFrame: self.window.frame
                                                pixelFormat: pixelFormat];
    [self.window setContentView:view];
    [self.window makeFirstResponder: view];
}

//==============================================================================

@end
