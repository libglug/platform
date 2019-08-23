#import "../system_platform.h"

#import <Foundation/NSProcessInfo.h>

unsigned int cpu_count(void)
{
    return (unsigned int)[[NSProcessInfo processInfo] processorCount];
}

unsigned int active_cpus(void)
{
    return (unsigned int)[[NSProcessInfo processInfo] activeProcessorCount];
}

uint64_t physical_mem(void)
{
    return [[NSProcessInfo processInfo] physicalMemory];
}
