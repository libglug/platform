#include <glug/platform/platform.h>
#include "platform_platform.h"

#include <stdlib.h>
#include <string.h>

enum glug_os glug_plat_os(struct glug_plat *plat)
{
    return plat->os();
}

bool glug_plat_os_version(struct glug_plat *plat, struct glug_plat_version *version)
{
    memset(version, 0, sizeof(struct glug_plat_version));
    return plat->os_version(version);
}

bool glug_plat_kernel_version(struct glug_plat *plat, struct glug_plat_version *version)
{
    memset(version, 0, sizeof(struct glug_plat_version));
    return plat->kernel_version(version);
}

struct glug_plat *glug_plat_init(void)
{
    struct glug_plat *plat = malloc(sizeof(struct glug_plat));

    plat->os = get_os_fcn();
    plat->os_version = get_os_version_fcn();
    plat->kernel_version = get_kernel_version_fcn();

    return plat;
}
