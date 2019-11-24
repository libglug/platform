#include "system.h"

#include <Windows.h>

uint32_t cpus_win(GetNSInfo_t get_native_sysinfo)
{
    SYSTEM_INFO sysinf;

    get_native_sysinfo(&sysinf);
    return sysinf.dwNumberOfProcessors;
}

uint32_t active_cpus_win(GetNSInfo_t get_native_sysinfo)
{
    uint32_t active = 0;
    SYSTEM_INFO sysinf;

    get_native_sysinfo(&sysinf);
    while(sysinf.dwActiveProcessorMask > 0)
    {
        active += sysinf.dwActiveProcessorMask & 1;
        sysinf.dwActiveProcessorMask >>= 1;
    }

    return active;
}

uint64_t physical_mem_win(GetPISMemory_t get_phys_mem)
{
    ULONGLONG bytes = 0;

    get_phys_mem(&bytes);
    return bytes * 1024;
}
