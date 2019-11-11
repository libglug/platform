#include <glug/os.h>

#if GLUG_OS == GLUG_OS_UNK

#include "platform_builder.h"
#include "null/platform.h"

void build_platform(struct glug_plat *platform)
{
    platform->os = os_null;
    platform->os_version = os_version_null;
    platform->kernel_version = kernel_version_null;
}

void teardown_platform(struct glug_plat *platform)
{
    (void) platform;
}

#endif
