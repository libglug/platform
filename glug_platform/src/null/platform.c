#include "platform.h"

enum glug_os os_null(void)
{
    return glug_os_unknown;
}

glug_bool os_version_null(struct glug_plat_version *version)
{
    (void) version;
    return false;
}

glug_bool kernel_version_null(struct glug_plat_version *version)
{   
    (void) version;
    return false;
}
