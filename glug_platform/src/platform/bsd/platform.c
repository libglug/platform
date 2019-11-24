#include "platform.h"

#include <stdio.h>
#include <sys/sysctl.h>

enum glug_os os_bsd()
{
    return glug_os_bsd;
}

void os_version_bsd(sysctl_t sysctl, struct glug_plat_version *version)
{
    kernel_version_bsd(sysctl, version);
}

void kernel_version_bsd(sysctl_t sysctl, struct glug_plat_version *version)
{
    size_t len = 25;
    char release[25];
    int mib[2];

    mib[0] = CTL_KERN;
    mib[1] = KERN_OSRELEASE;
    if (sysctl(mib, 2, release, &len, (void *)0, 0) == -1)
        return;

    sscanf(release, "%u.%u.%u", &version->major, &version->minor, &version->patch);
}
