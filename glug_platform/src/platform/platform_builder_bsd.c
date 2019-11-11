#include "platform_builder.h"
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_BSD
#include "bsd/platform.h"

void build_platform(struct glug_plat *platform)
{
    platform->os = os_bsd;
    platform->os_version = os_version_bsd;
    platform->kernel_version = kernel_version_bsd;
}

#endif // GLUG_OS == GLUG_OS_BSD
