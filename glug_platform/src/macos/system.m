#include "system.h"

#include <Foundation/NSProcessInfo.h>

uint32_t cpu_count_mac()
{
    return (uint32_t)[[NSProcessInfo processInfo] processorCount];
}

uint32_t active_cpus_mac()
{
    return (uint32_t)[[NSProcessInfo processInfo] activeProcessorCount];
}

uint64_t physical_mem_mac()
{
    return [[NSProcessInfo processInfo] physicalMemory];
}
