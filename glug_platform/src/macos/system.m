#include "system.h"

#include <Foundation/NSProcessInfo.h>

glug_bool cpu_count_mac(uint32_t *ncpu)
{
    *ncpu = (uint32_t)[[NSProcessInfo processInfo] processorCount];
    return true;
}

glug_bool active_cpus_mac(uint32_t *ncpu)
{
    *ncpu = (uint32_t)[[NSProcessInfo processInfo] activeProcessorCount];
    return true;
}

glug_bool physical_mem_mac(uint64_t *bytes)
{
    *bytes = [[NSProcessInfo processInfo] physicalMemory];
    return true;
}
