#ifndef __DEVTOOLS_EMSCRIPTEN_H__
#define __DEVTOOLS_EMSCRIPTEN_H__

#include "platform/PlatformConfig.h"
#if AX_TARGET_PLATFORM == AX_PLATFORM_WASM

#include "base/Scheduler.h"
#include "base/Director.h"

NS_AX_BEGIN

class DevToolsImpl
{
public:
    DevToolsImpl();

    void update(float /*dt*/);

    void step();

    void pause();

    void resume();

    static DevToolsImpl* getInstance();

private:
    unsigned int _tick;
    Scheduler* _scheduler;
    Director* _director;
};

NS_AX_END

#endif // AX_TARGET_PLATFORM == AX_PLATFORM_WASM
#endif // __DEVTOOLS_EMSCRIPTEN_H__