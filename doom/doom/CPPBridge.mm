//
//  CPPBridge.m
//  ganesha
//
//  Created by Mihail Terekhov on 22.07.2021.
//

#import <ganesha/ganesha.h>
#import <wad/wad.h>

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
    self.ganeshaEngine->renderGraph = [self loadContent];
    
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

- (spcGaneshaEngine::GRenderGraph)loadContent {
    spcGaneshaEngine::GRenderGraph newRenderGraph;
    
    const std::vector<spcGaneshaEngine::Vertex> vertexes = {
        { spcGaneshaEngine::GPoint(-0.5f, -0.3, -0.5f), spcGaneshaEngine::GPoint2D{2.0f, 0.0f} },
        { spcGaneshaEngine::GPoint(0.5f, -0.3, -0.5f), spcGaneshaEngine::GPoint2D{0.0f, 0.0f} },
        { spcGaneshaEngine::GPoint(0.5f, -0.3, 0.5f), spcGaneshaEngine::GPoint2D{0.0f, 2.0f} },
        { spcGaneshaEngine::GPoint(-0.5f, -0.3, 0.5f), spcGaneshaEngine::GPoint2D{2.0f, 2.0f} },
        
        { spcGaneshaEngine::GPoint(0.0f, -0.1, 0.0f), spcGaneshaEngine::GPoint2D{2.0f, 0.0f} },
        { spcGaneshaEngine::GPoint(1.0f, -0.1, 0.0f), spcGaneshaEngine::GPoint2D{0.0f, 0.0f} },
        { spcGaneshaEngine::GPoint(1.0f, -0.1, 1.0f), spcGaneshaEngine::GPoint2D{0.0f, 2.0f} },
        { spcGaneshaEngine::GPoint(0.0f, -0.1, 1.0f), spcGaneshaEngine::GPoint2D{2.0f, 2.0f} },
        
        { spcGaneshaEngine::GPoint(-2.5f, 0.0f, -2.5f), spcGaneshaEngine::GPoint2D{2.0f, 0.0f} },
        { spcGaneshaEngine::GPoint(2.5f, 0.0f, -2.5f), spcGaneshaEngine::GPoint2D{0.0f, 0.0f} },
        { spcGaneshaEngine::GPoint(2.5f, 0.0f, 2.5f), spcGaneshaEngine::GPoint2D{0.0f, 2.0f} },
        { spcGaneshaEngine::GPoint(-2.5f, 0.0f, 2.5f), spcGaneshaEngine::GPoint2D{2.0f, 2.0f} }
    };
    newRenderGraph.defineVertexesArray(vertexes);
    
    const spcGaneshaEngine::TIndexArray indexes = {
        2, 1, 0, 0, 3, 2,
        6, 5, 4, 4, 7, 6,
        10, 9, 8, 8, 11, 10
    };
    newRenderGraph.defineIndexesArray(indexes);
    
    //  Load texture shader
    NSString *filePath = [NSBundle.mainBundle pathForResource: @"frag.spv" ofType: nil];
    newRenderGraph.pushFragmentShader(filePath.UTF8String);
    
    //  load vertex shader
    filePath = [NSBundle.mainBundle pathForResource: @"vert.spv" ofType: nil];
    newRenderGraph.pushVertexShader(filePath.UTF8String);
    
    filePath = [NSBundle.mainBundle pathForResource: @"BIGDOOR2.tga" ofType: nil];
    newRenderGraph.pushTextureFilePath(filePath.UTF8String);
    
    spcGaneshaEngine::GGraphNode *spriteNode = newRenderGraph.createSpriteNode(filePath.UTF8String);
    newRenderGraph.pushNode(spriteNode);
    
    return newRenderGraph;
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
    
//    spcWAD::ALevel e1m8 = wad.readLevel("MAP12");
//    const spcWAD::TThingList& levelItemsList = e1m8.levelItemsList();
//    int c = 0;
//    printf("THINGS\n");
//    spcWAD::AThing thing(0);
//    for (spcWAD::TThingListConstIter iter = levelItemsList.begin(); iter != levelItemsList.end(); iter++) {
//        if (iter->spritePrefix() == "TROO") {
//            thing = *iter;
//            break;
//        }
//        printf("%i. <%s>\n", ++c, iter->spritePrefix().c_str());
//    }
//    
//    const spcWAD::ASprite& sprite = e1m8.findSprite(thing);
//    printf("sprite <%s>\n", sprite.spritesPrefix.c_str());
}

@end
