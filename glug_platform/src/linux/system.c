#include "../system_platform.h"

#include <unistd.h>

unsigned int cpu_count(void)
{
    return (unsigned int)sysconf(_SC_NPROCESSORS_CONF);
}

unsigned int active_cpus(void)
{
    return (unsigned int)sysconf(_SC_NPROCESSORS_ONLN);
}

uint64_t physical_mem(void)
{
    return (uint64_t)sysconf(_SC_PHYS_PAGES) * (uint64_t)sysconf(_SC_PAGESIZE);
}
