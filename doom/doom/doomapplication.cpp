#include "doomapplication.h"

DoomApplication::DoomApplication(void *metalLayer) : spcGaneshaEngine::GApplication(std::make_shared<spcGaneshaEngine::GEventsService>()) {
    //  create layers service dependency
    std::shared_ptr<spcGaneshaEngine::GLayer> vulkanLayer = std::make_shared<spcGaneshaEngine::GVULKANLayer>("DOOM", metalLayer, eventsService);
    std::shared_ptr<spcGaneshaEngine::GLayer> systemLayer = std::make_shared<spcGaneshaEngine::GSystemLayer>("", eventsService);
    pushLayer(systemLayer);
    pushLayer(vulkanLayer);
}

DoomApplication::~DoomApplication() {
}

void DoomApplication::initGame() {
    eventsService->upda
    //    spcGaneshaEngine::GScene content = [self loadContent];
    //    content.viewport.width = CGRectGetWidth(layer.bounds);
    //    content.viewport.height = CGRectGetHeight(layer.bounds);
}

void DoomApplication::loadContent(const std::string& gundleFilePath) {
    spcGaneshaEngine::GEventShell shellEvent = eventsService->loadGundle(gundleFilePath);
    handleEvent(shellEvent);

    //    spcGaneshaEngine::GScene scene;
    //
    //    std::shared_ptr<spcGaneshaEngine::GShadersServiceProtocol> shadersService = std::make_shared<spcGaneshaEngine::GShadersService>();
    //    std::shared_ptr<spcGaneshaEngine::GImageServiceProtocol> imageService = std::make_shared<spcGaneshaEngine::GImageService>();
    //
    //    //  Load texture shader
    //    NSString *filePath = [NSBundle.mainBundle pathForResource: @"frag.spv" ofType: nil];
    //    scene.fragmentShadersArray.push_back(shadersService->createFragmentShader(filePath.UTF8String));
    //
    //    //  load vertex shader
    //    filePath = [NSBundle.mainBundle pathForResource: @"vert.spv" ofType: nil];
    //    scene.vertexShadersArray.push_back(shadersService->createVertexShader(filePath.UTF8String));
    //
    //    filePath = [NSBundle.mainBundle pathForResource: @"FLOOR5_2.tga" ofType: nil];
    //    scene.materialsArray.push_back(imageService->createImage(filePath.UTF8String));
    //
    //    filePath = [NSBundle.mainBundle pathForResource: @"BIGDOOR2.tga" ofType: nil];
    //    scene.materialsArray.push_back(imageService->createImage(filePath.UTF8String));
    //
    //    scene.cameraData.eyePoint = spcGaneshaEngine::GPoint(1, 1, 1);
    //    scene.cameraData.targetPoint = spcGaneshaEngine::GPoint(0, 0, 0);
    //    scene.cameraData.upVector = spcGaneshaEngine::GVector(0, 1, 0);
    //
    //    return scene;
}
void DoomApplication::processKeyboardEvent(const spcGaneshaEngine::TUInt keyCode) {
    spcGaneshaEngine::GEventShell shellEvent = eventsService->keyboardEvent(keyCode);
    handleEvent(shellEvent);
}

void DoomApplication::processMouseMove(const spcGaneshaEngine::TFloat diff_x, const spcGaneshaEngine::TFloat diff_y) {
    spcGaneshaEngine::GEventShell shellEvent = eventsService->mouseEvent(diff_x, diff_y);
    handleEvent(shellEvent);
}

void DoomApplication::renderFrame() {
    processRunLoop();
}

void DoomApplication::updateFrameSize(const spcGaneshaEngine::TFloat width, const spcGaneshaEngine::TFloat height) {
    spcGaneshaEngine::GViewport newViewport;
    
    newViewport.width = width;
    newViewport.height = height;
    
    spcGaneshaEngine::GEventShell shellEvent = eventsService->updateViewportEvent(newViewport);
    self.doomApplication->handleEvent(shellEvent);
}

//- (void)processWAD: (NSString *)wadFilePath {
//    spcWAD::AWAD wad(wadFilePath.UTF8String);
//    for (int i = 0; i < 32; i++) {
//        std::string mapname = "MAP";
//        if (i < 10) {
//            mapname += "0";
//        }
//        mapname += std::to_string(i);
//        spcWAD::ALevel e1m8 = wad.readLevel(mapname);
//    }
//}

