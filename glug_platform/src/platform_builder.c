#include "platform_builder.h"

#include <glug/os.h>

#if defined(GLUG_OS_WIN)

#include "win32/platform.h"

void build_platform(struct glug_plat *platform)
{
    platform->os = os_win;
    platform->os_version = os_version_win;
    platform->kernel_version = kernel_version_win;
}

#elif defined(GLUG_OS_MAC)

#include "macos/platform.h"

void build_platform(struct glug_plat *platform)
{
    platform->os = os_mac;
    platform->os_version = os_version_mac;
    platform->kernel_version = kernel_version_mac;
}

#elif defined(GLUG_OS_LIN)

#include "linux/platform.h"
#include "posix/platform.h"

void build_platform(struct glug_plat *platform)
{
    platform->os = os_linux;
    platform->os_version = os_version_linux;
    platform->kernel_version = kernel_version_linux;
}

#elif defined(GLUG_OS_BSD)

#include "bsd/platform.h"

void build_platform(struct glug_plat *platform)
{
    platform->os = os_bsd;
    platform->os_version = os_version_bsd;
    platform->kernel_version = kernel_version_bsd;
}

#endif
