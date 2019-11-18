#include "platform.h"
#include "platform_context.h"

#include <stdio.h>
#include <sys/sysctl.h>

enum glug_os os_bsd()
{
    return glug_os_bsd;
}

void os_version_bsd(struct glug_plat_version *version, const struct bsd_context *context)
{
    kernel_version_bsd(version, context);
}

void kernel_version_bsd(struct glug_plat_version *version, const struct bsd_context *context)
{
    size_t len = 25;
    char release[25];
    int mib[2];

    mib[0] = CTL_KERN;
    mib[1] = KERN_OSRELEASE;
    if (context->sysctl(mib, 2, release, &len, (void *)0, 0) == -1)
        return;

    if(!sscanf(release, "%u.%u.%u", &version->major, &version->minor, &version->patch))
        sscanf(release, "%u.%u", &version->major, &version->minor);
}
