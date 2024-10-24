#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface DoomApplicationProxy : NSObject

- (instancetype)initWithMetalLayer: (nullable CALayer *) metalLayer;
- (void)initGame;
- (void)loadContentWithGundleFilePath: (NSString *) gundleFilePath;
- (void)processKeyboardEventWithKeyCode: (uint16_t)keyCode;
- (void)processMouseMoveWithDiff_x: (CGFloat) diff_x
                            diff_y: (CGFloat) diff_y;
- (void)renderFrame;
- (void)updateFrameSizeWithSize: (CGSize) size;

@end

NS_ASSUME_NONNULL_END
