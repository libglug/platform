#include "system.h"

#include <sys/types.h>
#include <sys/sysctl.h>
#include <unistd.h>

glug_bool cpu_count_bsd(uint32_t *ncpu)
{
    int mib[2];
    size_t len = sizeof(ncpu);

    mib[0] = CTL_HW;
    mib[1] = HW_NCPU;
    sysctl(mib, 2, ncpu, &len, (void *)0, 0);

    return *ncpu > 0;
}

glug_bool active_cpus_bsd(uint32_t *ncpu)
{
    int mib[2];
    size_t len = sizeof(ncpu), elems = 2;

#ifdef HW_AVAILCPU
    mib[0] = CTL_HW;
    mib[1] = HW_AVAILCPU;
#else
    sysctlbyname("hw.availcpu", mib, &elems, (void *)0, 0);
#endif
    sysctl(mib, 2, ncpu, &len, (void *)0, 0);

    return *ncpu > 0;
}

glug_bool physical_mem_bsd(uint64_t *bytes)
{
    int mib[2];
    size_t len = sizeof(*bytes);

    mib[0] = CTL_HW;
    mib[1] = HW_PHYSMEM;
    sysctl(mib, 2, bytes, &len, (void *)0, 0);

    return *bytes > 0;
}
