#include "DoomApplicationFabric.h"

spcGaneshaEngine::GApplication *DoomApplicationFabric::createApplication(void *metalLayer, spcGaneshaEngine::GGaneshaContent& content) {
    //  create events service dependency
    spcGaneshaEngine::GEventsServiceProtocol *eventsService = new spcGaneshaEngine::GEventsService();
    eventsService->init();

    //  create layers service dependency
    spcGaneshaEngine::GLayer *vulkanLayer = new spcGaneshaEngine::GVULKANLayer(metalLayer, content, eventsService);
    spcGaneshaEngine::GLayer *systemLayer = new spcGaneshaEngine::GSystemLayer("", content, eventsService);
    spcGaneshaEngine::GLayersServiceProtocol *layersService = new spcGaneshaEngine::GLayersService();
    layersService->init();
    layersService->pushLayer(systemLayer);
    layersService->pushLayer(vulkanLayer);
    
    //  create application
    spcGaneshaEngine::GApplication *newApplication = new spcGaneshaEngine::GApplication(eventsService, layersService, metalLayer, content);
    return newApplication;
}
