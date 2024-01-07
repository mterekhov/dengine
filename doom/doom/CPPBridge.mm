//
//  CPPBridge.m
//  ganesha
//
//  Created by Mihail Terekhov on 22.07.2021.
//

#import <ganesha/ganesha.h>

#import "CPPBridge.h"

@interface CPPBridge ()

@property (nonatomic, assign) spcGaneshaEngine::GGanesha *ganeshaEngine;

@end

@implementation CPPBridge

- (void)dealloc {
    self.ganeshaEngine->destroyVulkan();
    delete self.ganeshaEngine;
}

- (void)launchEngineWithLayer:(nullable CALayer *) layer {
    if (!layer) {
        NSLog(@"ACHTUNG: layer is nil");
        return;
    }
    
    self.ganeshaEngine = new spcGaneshaEngine::GGanesha();
    if (!self.ganeshaEngine->initEngine((__bridge void *)layer,
                                        static_cast<spcGaneshaEngine::TUInt>(CGRectGetWidth(layer.bounds)),
                                        static_cast<spcGaneshaEngine::TUInt>(CGRectGetHeight(layer.bounds)))) {
        NSLog(@"ACHTUNG: no chance to create VULKAN instance");
        return;
    }
}

- (void)stopEngine {
    self.ganeshaEngine->destroyVulkan();
}

- (void)drawableSizeWillChange: (CGSize)size {
    self.ganeshaEngine->setViewSize(size.width, size.height);
}

- (void)drawFrame {
    self.ganeshaEngine->mainLoop();
}

- (void)processKeyboardEventWithKeyCode: (uint16_t)keyCode {
    self.ganeshaEngine->processKeyboard(keyCode);
}

- (void)processMouseMoveWithDiffX: (CGFloat) diff_x
                           diff_y: (CGFloat) diff_y {
    self.ganeshaEngine->processMouseMove(diff_x, diff_y);
}

@end
