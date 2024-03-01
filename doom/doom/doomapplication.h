#ifndef SPCGANESHAENGINE_DOOMAPPLICATION_H
#define SPCGANESHAENGINE_DOOMAPPLICATION_H

#include <ganesha/ganesha.h>

class DoomApplication : public spcGaneshaEngine::GApplication {
public:
    DoomApplication(void *metalLayer, const spcGaneshaEngine::GGaneshaContent& loadContent);
    virtual ~DoomApplication();
};

#endif  //  SPCGANESHAENGINE_DOOMAPPLICATION_H

