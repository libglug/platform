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

enum glug_os os_plat(const struct glug_plat *platform)
{
    (void) platform;

    return os_null();
}

void os_version_plat(const struct glug_plat *platform, struct glug_plat_version *version)
{
    (void) version;
    (void) platform;

    os_version_null();
}

void kernel_version_plat(const struct glug_plat *platform, struct glug_plat_version *version)
{
    (void) version;
    (void) platform;

    os_version_null();
}

#endif // GLUG_OS == GLUG_OS_UNK
