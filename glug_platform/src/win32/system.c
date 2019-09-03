#include "system.h"

#include <Windows.h>

uint32_t cpu_count_win(void)
{
    SYSTEM_INFO sysinf;
    GetNativeSystemInfo(&sysinf);

    return sysinf.dwNumberOfProcessors;
}

uint32_t active_cpus_win(void)
{
    uint32_t active = 0;
    SYSTEM_INFO sysinf;

    GetNativeSystemInfo(&sysinf);
    while(sysinf.dwActiveProcessorMask > 0)
    {
        active += sysinf.dwActiveProcessorMask & 1;
        sysinf.dwActiveProcessorMask >>= 1;
    }

    return active;
}

uint64_t physical_mem_win(void)
{
    ULONGLONG bytes = 0;
    GetPhysicallyInstalledSystemMemory(&bytes);

    return bytes;
}
