#include "system.h"

#include <sys/types.h>
#include <sys/sysctl.h>
#include <unistd.h>

uint32_t cpus_bsd(sysctl_t sysctl)
{
    uint32_t ncpu = 0;
    int mib[2];
    size_t len = sizeof(ncpu);

    mib[0] = CTL_HW;
    mib[1] = HW_NCPU;
    sysctl(mib, 2, &ncpu, &len, (void *)0, 0);

    return ncpu;
}

uint32_t active_cpus_bsd(sysconf_t sysconf)
{
    long ncpu = sysconf(_SC_NPROCESSORS_ONLN);

    if (ncpu == -1) return 0;
    return (uint32_t)ncpu;
}

uint64_t physical_mem_bsd(sysctl_t sysctl)
{
    uint64_t bytes = 0;
    int mib[2];
    size_t len = sizeof(bytes);

    mib[0] = CTL_HW;
    mib[1] = HW_REALMEM;
    sysctl(mib, 2, &bytes, &len, (void *)0, 0);

    return bytes;
}
