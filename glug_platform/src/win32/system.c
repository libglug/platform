#include "../system_platform.h"

#include <Windows.h>

static bool cpu_count(uint32_t *ncpu)
{
    SYSTEM_INFO sysinf;
    GetSystemInfo(&sysinf);

    *ncpu = sysinf.dwNumberOfProcessors;
    return true;
}

static bool active_cpus(uint32_t *ncpu)
{
    unsigned int active = 0;
    SYSTEM_INFO sysinf;

    GetSystemInfo(&sysinf);
    while(sysinf.dwActiveProcessorMask > 0)
    {
        active += sysinf.dwActiveProcessorMask & 1;
        sysinf.dwActiveProcessorMask >>= 1;
    }

    *ncpu = active;
    return true;
}

static bool physical_mem(uint64_t *bytes)
{
    MEMORYSTATUSEX memstat;
    memstat.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memstat);

    *bytes = memstat.ullTotalPhys;
    return true;
}

bool (*get_cpu_count_win(void))(uint32_t *)
{
    return cpu_count;
}

bool (*get_active_cpus_win(void))(uint32_t *)
{
    return active_cpus;
}

bool (*get_physical_mem_win(void))(uint64_t *)
{
    return physical_mem;
}
