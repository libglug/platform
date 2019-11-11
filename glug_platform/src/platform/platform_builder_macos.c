#include <glug/os.h>

#if GLUG_OS == GLUG_OS_MAC

#include "platform_builder.h"
#include "macos/platform.h"

void build_platform(struct glug_plat *platform)
{
    platform->os = os_mac;
    platform->os_version = responds_to_osversion() ? os_version_mac : os_version_fallback_mac;
    platform->kernel_version = kernel_version_mac;
}

void teardown_platform(struct glug_plat *platform)
{
    (void) platform;
}

#endif // GLUG_OS == GLUG_OS_MAC
