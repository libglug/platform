#include "../system_platform.h"

#include <Windows.h>

unsigned int cpu_count()
{
    SYSTEM_INFO sysinf;
    GetSystemInfo(&sysinf);

    return sysinf.dwNumberOfProcessors;
}

unsigned int active_cpus()
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

uint64_t physical_mem()
{
    MEMORYSTATUSEX memstat;
    memstat.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memstat);

    return memstat.ullTotalPhys;
}
