#ifndef DOOMAPPLICATIONFABRIC_H
#define DOOMAPPLICATIONFABRIC_H

#include <ganesha/ganesha.h>

class DoomApplicationFabric {
public:
    static spcGaneshaEngine::GApplication *createApplication(void *metalLayer, spcGaneshaEngine::GGaneshaContent& content);
};

#endif  //  DOOMAPPLICATIONFABRIC_H
