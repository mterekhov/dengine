#include "doomapplication.h"

DoomApplication::DoomApplication(void *metalLayer, const spcGaneshaEngine::GGaneshaContent& loadContent) : spcGaneshaEngine::GApplication(nullptr, nullptr, metalLayer, loadContent) {
    //  create events service dependency
    spcGaneshaEngine::GEventsServiceProtocol *newEventsService = new spcGaneshaEngine::GEventsService();
    newEventsService->init();

    //  create layers service dependency
    spcGaneshaEngine::GLayer *vulkanLayer = new spcGaneshaEngine::GVULKANLayer(metalLayer, content, newEventsService);
    spcGaneshaEngine::GLayer *systemLayer = new spcGaneshaEngine::GSystemLayer("", content, newEventsService);
    spcGaneshaEngine::GLayersServiceProtocol *newLayersService = new spcGaneshaEngine::GLayersService();
    newLayersService->init();
    newLayersService->pushLayer(systemLayer);
    newLayersService->pushLayer(vulkanLayer);
    
    eventsService = newEventsService;
    layerService = newLayersService;
}

DoomApplication::~DoomApplication() {
}
