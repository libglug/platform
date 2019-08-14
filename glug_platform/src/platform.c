#include <glug/platform/platform.h>
#include "platform_platform.h"

enum glug_os glug_plat_get_os()
{
    return glug_os_unknown;
}

struct glug_os_version glug_plat_os_version()
{
    struct glug_os_version version = {0};
    os_version(&version);

    return version;
}
