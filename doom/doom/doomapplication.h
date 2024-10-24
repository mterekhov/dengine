#ifndef DOOMAPPLICATION_H
#define DOOMAPPLICATION_H

#include <ganesha/ganesha.h>

class DoomApplication : public spcGaneshaEngine::GApplication {
public:
    DoomApplication(void *metalLayer);
    virtual ~DoomApplication();
    
    void initGame();
    void loadContent(const std::string& gundleFilePath);
    void processKeyboardEvent(const spcGaneshaEngine::TUInt keyCode);
    void processMouseMove(const spcGaneshaEngine::TFloat diff_x, const spcGaneshaEngine::TFloat diff_y);
    void renderFrame();
    void updateFrameSize(const spcGaneshaEngine::TFloat width, const spcGaneshaEngine::TFloat height);
};

#endif  //  DOOMAPPLICATION_H

