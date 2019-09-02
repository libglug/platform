#include "system.h"

#include <Windows.h>

glug_bool cpu_count_win(uint32_t *ncpu)
{
    SYSTEM_INFO sysinf;
    GetSystemInfo(&sysinf);

    *ncpu = sysinf.dwNumberOfProcessors;
    return true;
}

glug_bool active_cpus_win(uint32_t *ncpu)
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

glug_bool physical_mem_win(uint64_t *bytes)
{
    MEMORYSTATUSEX memstat;
    memstat.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memstat);

    *bytes = memstat.ullTotalPhys;
    return true;
}
