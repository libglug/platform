#include <glug/platform/platform.h>
#include "platform_platform.h"

#include <string.h>

enum glug_os glug_plat_get_os()
{
    return glug_os_unknown;
}

int glug_plat_os_version(struct glug_plat_version *version)
{
    memset(version, 0, sizeof(struct glug_plat_version));
    return os_version(version);
}
