#include "system.h"

#include <sys/types.h>
#include <sys/sysctl.h>
#include <unistd.h>

uint32_t cpu_count_bsd(void)
{
    uint32_t ncpu = 0;
    int mib[2];
    size_t len = sizeof(ncpu);

    mib[0] = CTL_HW;
    mib[1] = HW_NCPU;
    sysctl(mib, 2, &ncpu, &len, (void *)0, 0);

    return ncpu;
}

uint32_t active_cpus_bsd(void)
{
    uint32_t ncpu = 0;

#if defined(HW_AVAILCPU)
    int mib[2];
    size_t len = sizeof(ncpu);
    mib[0] = CTL_HW;
    mib[1] = HW_AVAILCPU;
    sysctl(mib, 2, &ncpu, &len, (void *)0, 0);
#elif defined(__FreeBSD__)
    size_t len = sizeof(ncpu);
    sysctlbyname("hw.availcpu", &ncpu, &len, (void *)0, 0);
#endif

    return ncpu;
}

uint64_t physical_mem_bsd(void)
{
    uint64_t bytes = 0;
    int mib[2];
    size_t len = sizeof(bytes);

    mib[0] = CTL_HW;
    mib[1] = HW_PHYSMEM;
    sysctl(mib, 2, &bytes, &len, (void *)0, 0);

    return bytes;
}
