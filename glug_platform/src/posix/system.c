#include "system.h"

#include <unistd.h>

uint32_t cpu_count_posix()
{
    long cpus = sysconf(_SC_NPROCESSORS_CONF);

    if (cpus == -1) return 0;

    return (uint32_t)cpus;
}

uint32_t active_cpus_posix()
{
    long cpus = sysconf(_SC_NPROCESSORS_ONLN);

    if (cpus == -1) return 0;

    return (uint32_t)cpus;
}

uint64_t physical_mem_posix()
{
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_sz = sysconf(_SC_PAGESIZE);

    if (pages == -1 || pages == -1) return 0;

    return (uint64_t)pages * (uint64_t)page_sz;
}
