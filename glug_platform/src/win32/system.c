#include "../system_platform.h"

#include <Windows.h>

static uint32_t cpu_count(void)
{
    SYSTEM_INFO sysinf;
    GetSystemInfo(&sysinf);

    return sysinf.dwNumberOfProcessors;
}

static uint32_t active_cpus(void)
{
    unsigned int active = 0;
    SYSTEM_INFO sysinf;

    GetSystemInfo(&sysinf);
    while(sysinf.dwActiveProcessorMask > 0)
    {
        active += sysinf.dwActiveProcessorMask & 1;
        sysinf.dwActiveProcessorMask >>= 1;
    }

    return active;
}

static uint64_t physical_mem(void)
{
    MEMORYSTATUSEX memstat;
    memstat.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memstat);

    return memstat.ullTotalPhys;
}

uint32_t (*get_cpu_count_fcn(void))(void)
{
    return cpu_count;
}

uint32_t (*get_active_cpus_fcn(void))(void)
{
    return active_cpus;
}

uint64_t (*get_physical_mem_fcn(void))(void)
{
    return physical_mem;
}
