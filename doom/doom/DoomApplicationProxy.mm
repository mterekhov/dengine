//
//  CPPBridge.m
//  ganesha
//
//  Created by Mihail Terekhov on 22.07.2021.
//

#import <ganesha/ganesha.h>

#import "DoomApplicationProxy.h"
#import "doomapplication.h"

@interface DoomApplicationProxy ()

@property (nonatomic, assign) std::shared_ptr<DoomApplication> doomApplication;

@end

@implementation DoomApplicationProxy

- (instancetype)initWithMetalLayer: (nullable CALayer *) metalLayer {
    self = [super init];
    if (self) {
        self.doomApplication = std::make_shared<DoomApplication>((__bridge void *)metalLayer);
    }
    
    return self;
}

- (void)dealloc {
}

- (void)initGame {
    self.doomApplication->initGame();
}

- (void)loadContentWithGundleFilePath: (NSString *) gundleFilePath {
    self.doomApplication->loadContent(gundleFilePath.UTF8String);
}

- (void)processKeyboardEventWithKeyCode: (uint16_t)keyCode {
    self.doomApplication->processKeyboardEvent(keyCode);
}

- (void)processMouseMoveWithDiff_x: (CGFloat) diff_x
                            diff_y: (CGFloat) diff_y {
    self.doomApplication->processMouseMove(diff_x, diff_y);
}

- (void)renderFrame {
    self.doomApplication->renderFrame();
}

- (void)updateFrameSizeWithSize: (CGSize) size {
    self.doomApplication->updateFrameSize(size.width, size.height);
}

@end
