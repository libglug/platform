#include "platform.h"
#include "platform_context.h"

#include <sys/utsname.h>
#include <stdio.h>

enum glug_os os_posix(const struct posix_context *context)
{
    (void) context;

    return glug_os_linux;
}

glug_bool os_version_posix(struct glug_plat_version *version, const struct posix_context *context)
{
    // TODO: set version
}

glug_bool kernel_version_posix(struct glug_plat_version *version, const struct posix_context *context)
{
    struct utsname utsname;
    int res = context->uname(&utsname);

    if (res == -1)
        return false;

    sscanf(utsname.release, "%u.%u.%u", &version->major, &version->minor, &version->patch);

    return true;
}
