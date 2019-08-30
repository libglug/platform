#import "../system_platform.h"

#import <Foundation/NSProcessInfo.h>

static bool cpu_count(uint32_t *ncpu)
{
    *ncpu = (uint32_t)[[NSProcessInfo processInfo] processorCount];
    return true;
}

static bool active_cpus(uint32_t *ncpu)
{
    *ncpu = (uint32_t)[[NSProcessInfo processInfo] activeProcessorCount];
    return true;
}

static bool physical_mem(uint64_t *bytes)
{
    *bytes =  [[NSProcessInfo processInfo] physicalMemory];
    return true;
}

bool (*get_cpu_count_mac(void))(uint32_t *)
{
    return cpu_count;
}

bool (*get_active_cpus_mac(void))(uint32_t *)
{
    return active_cpus;
}

bool (*get_physical_mem_mac(void))(uint64_t *)
{
    return physical_mem;
}
