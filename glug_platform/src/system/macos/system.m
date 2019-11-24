#include "system.h"

#include <Foundation/NSProcessInfo.h>

uint32_t cpus_mac(void)
{
    return (uint32_t)[[NSProcessInfo processInfo] processorCount];
}

uint32_t active_cpus_mac(void)
{
    return (uint32_t)[[NSProcessInfo processInfo] activeProcessorCount];
}

uint64_t physical_mem_mac(void)
{
    return [[NSProcessInfo processInfo] physicalMemory];
}
