#include <glug/platform/platform.h>
#include "platform_builder.h"

#include <stdlib.h>
#include <string.h>

struct glug_plat *glug_plat_create(void)
{
    struct glug_plat *plat = malloc(sizeof(struct glug_plat));
    if (plat)
        build_platform(plat);

    return plat;
}

struct glug_plat *glug_plat_free(struct glug_plat *platform)
{
    free_platform(platform);
    if (platform)
        free(platform);

    return NULL;
}

enum glug_os glug_plat_os(struct glug_plat *plat)
{
    return plat->os(&plat->plat_context);
}

glug_bool glug_plat_os_version(struct glug_plat *plat, struct glug_plat_version *version)
{
    memset(version, 0, sizeof(struct glug_plat_version));
    return plat->os_version(version, &plat->plat_context);
}

glug_bool glug_plat_kernel_version(struct glug_plat *plat, struct glug_plat_version *version)
{
    memset(version, 0, sizeof(struct glug_plat_version));
    return plat->kernel_version(version, &plat->plat_context);
}
