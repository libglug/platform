#include <glug/platform/platform.h>
#include "platform_builder.h"
#include "null/platform.h"

#include <stdlib.h>
#include <string.h>

struct glug_plat *glug_plat_create(void)
{
    struct glug_plat *plat = malloc(sizeof(struct glug_plat));
    if (plat)
    {
        plat->os = os_null;
        plat->os_version = os_version_null;
        plat->kernel_version = kernel_version_null;
        build_platform(plat);
    }

    return plat;
}

struct glug_plat *glug_plat_free(struct glug_plat *platform)
{
    teardown_platform(platform);
    if (platform)
        free(platform);

    return NULL;
}

enum glug_os glug_plat_os(struct glug_plat *plat)
{
    return plat->os(&plat->plat_context);
}

void glug_plat_os_version(struct glug_plat *plat, struct glug_plat_version *version)
{
    memset(version, 0, sizeof(struct glug_plat_version));
    plat->os_version(version, &plat->plat_context);
}

void glug_plat_kernel_version(struct glug_plat *plat, struct glug_plat_version *version)
{
    memset(version, 0, sizeof(struct glug_plat_version));
    plat->kernel_version(version, &plat->plat_context);
}