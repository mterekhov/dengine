//
//  CPPBridge.m
//  ganesha
//
//  Created by Mihail Terekhov on 22.07.2021.
//

#import <ganesha/ganesha.h>
#import <wad/wad.h>

#import "CPPBridge.h"
#import "DoomApplicationFabric.h"

@interface CPPBridge ()

@property (nonatomic, assign) spcGaneshaEngine::GApplication *doomGame;

@end

@implementation CPPBridge

- (void)dealloc {

}

- (void)launchEngineWithLayer:(nullable CALayer *) layer {
    spcGaneshaEngine::GGaneshaContent content = [self loadContent];
    content.viewport.width = CGRectGetWidth(layer.bounds);
    content.viewport.height = CGRectGetHeight(layer.bounds);
    self.doomGame = DoomApplicationFabric::createApplication((__bridge void *)layer,
                                                             content);
}

- (void)stopEngine {
//    self.ganeshaEngine->destroyVulkan();
}

- (void)drawableSizeWillChange: (CGSize)size {
    spcGaneshaEngine::GEventShell shellEvent = self.doomGame->eventsService->windowEvent(size.width, size.height);
    self.doomGame->handleEvent(shellEvent);
}

- (void)drawFrame {
    self.doomGame->processRunLoop();
}

- (void)processKeyboardEventWithKeyCode: (uint16_t)keyCode {
    spcGaneshaEngine::GEventShell shellEvent = self.doomGame->eventsService->keyboardEvent(keyCode);
    self.doomGame->handleEvent(shellEvent);
}

- (void)processMouseMoveWithDiffX: (CGFloat) diff_x
                           diff_y: (CGFloat) diff_y {
    spcGaneshaEngine::GEventShell shellEvent = self.doomGame->eventsService->mouseEvent(diff_x, diff_y);
    self.doomGame->handleEvent(shellEvent);
}

- (spcGaneshaEngine::GGaneshaContent)loadContent {
    spcGaneshaEngine::GGaneshaContent content;

    //  Load texture shader
    NSString *filePath = [NSBundle.mainBundle pathForResource: @"frag.spv" ofType: nil];
    content.addFragmentShader(filePath.UTF8String);
    
    //  load vertex shader
    filePath = [NSBundle.mainBundle pathForResource: @"vert.spv" ofType: nil];
    content.addVertexShader(filePath.UTF8String);
    
    filePath = [NSBundle.mainBundle pathForResource: @"BIGDOOR2.tga" ofType: nil];
    content.addSprite(filePath.UTF8String);
    
    content.cameraData.positionPoint = spcGaneshaEngine::GPoint(0, -1, 10);
    
    return content;
}

- (void)processWAD: (NSString *)wadFilePath {
    spcWAD::AWAD wad(wadFilePath.UTF8String);
    for (int i = 0; i < 32; i++) {
        std::string mapname = "MAP";
        if (i < 10) {
            mapname += "0";
        }
        mapname += std::to_string(i);
        spcWAD::ALevel e1m8 = wad.readLevel(mapname);
    }
}

@end
