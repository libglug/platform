#include "Windows.h"

#include <stdio.h>

static SYSTEM_INFO sys = {0};

void set_system_cpus(unsigned long cpus, unsigned long long mask)
{
    sys.dwNumberOfProcessors = cpus;
    sys.dwActiveProcessorMask = mask;
}

void GetNativeSystemInfo(SYSTEM_INFO *sysinfo)
{
    sysinfo->dwNumberOfProcessors = sys.dwNumberOfProcessors;
    sysinfo->dwActiveProcessorMask = sys.dwActiveProcessorMask;
}

static int should_fail_mem = 0;
static unsigned long long physical_memory = 0;

void set_memory(unsigned long long bytes)
{
    physical_memory = bytes;
}

void set_memory_failure_count(int failures)
{
    should_fail_mem = failures;
}

int GetPhysicallyInstalledSystemMemory(unsigned long long *bytes)
{
    if (!should_fail_mem)
    {
        *bytes = physical_memory;
        return 1;
    }

    --should_fail_mem;
    return 0;
}

