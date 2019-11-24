#include <glug/platform/platform.h>
#include "platform_builder.h"

#include <stdlib.h>
#include <string.h>

struct glug_plat *glug_plat_create(void)
{
    struct glug_plat *plat = calloc(1, sizeof(struct glug_plat));
    if (plat)
        build_platform(plat);

    return plat;
}

struct glug_plat *glug_plat_free(struct glug_plat *platform)
{
    if (platform)
    {
        teardown_platform(platform);
        free(platform);
    }

    return NULL;
}

enum glug_os glug_plat_os(const struct glug_plat *platform)
{
    return os_plat(platform);
}

void glug_plat_os_version(const struct glug_plat *platform, struct glug_plat_version *version)
{
    memset(version, 0, sizeof(struct glug_plat_version));
    os_version_plat(platform, version);
}

void glug_plat_kernel_version(const struct glug_plat *platform, struct glug_plat_version *version)
{
    memset(version, 0, sizeof(struct glug_plat_version));
    kernel_version_plat(platform, version);
}
