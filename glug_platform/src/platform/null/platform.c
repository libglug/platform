#include "platform.h"

enum glug_os os_null(const void *context)
{
    (void) context;

    return glug_os_unknown;
}

void os_version_null(struct glug_plat_version *version, const void *context)
{
    (void) version;
    (void) context;
}

void kernel_version_null(struct glug_plat_version *version, const void *context)
{   
    (void) version;
    (void) context;
}
