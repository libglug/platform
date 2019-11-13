#include "platform_builder.h"
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_UNK
#include "null/platform.h"

void build_platform(struct glug_plat *platform)
{
    (void) platform;
}

void teardown_platform(struct glug_plat *platform)
{
    (void) platform;
}

#endif
