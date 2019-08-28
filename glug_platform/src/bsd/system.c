#include "system.h"

#include <sys/types.h>
#include <sys/sysctl.h>

static uint32_t cpu_count(void)
{
    int mib[2];
    uint32_t ncpu;
    size_t len = sizeof(ncpu);

    mib[0] = CTL_HW;
    mib[1] = HW_NCPU;
    sysctl(mib, 2, &ncpu, &len, (void *)0, 0);

    return ncpu;
}

static uint32_t active_cpus(void)
{
    int mib[2];
    uint32_t ncpu;
    size_t len = sizeof(ncpu);

    mib[0] = CTL_HW;
    mib[1] = HW_AVAILCPU;
    sysctl(mib, 2, &ncpu, &len, (void *)0, 0);

    return ncpu;
}

static uint64_t physical_mem(void)
{
    int mib[2];
    uint64_t membytes;
    size_t len = sizeof(membytes);

    mib[0] = CTL_HW;
    mib[1] = HW_PHYSMEM;
    sysctl(mib, 2, &membytes, &len, (void *)0, 0);

    return membytes;
}

uint32_t (*get_cpu_count_bsd(void))(void)
{
    return cpu_count;
}

uint32_t (*get_active_cpus_bsd(void))(void)
{
    return active_cpus;
}

uint64_t (*get_physical_mem_bsd(void))(void)
{
    return physical_mem;
}
