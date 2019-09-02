#include "system.h"

#include <unistd.h>

glug_bool cpu_count_posix(uint32_t *ncpu)
{
    long cpus = sysconf(_SC_NPROCESSORS_CONF);
    *ncpu = 0;

    if (cpus == -1) return false;

    *ncpu = (uint32_t)cpus;
    return true;
}

glug_bool active_cpus_posix(uint32_t *ncpu)
{
    long cpus = sysconf(_SC_NPROCESSORS_ONLN);
    *ncpu = 0;

    if (cpus == -1) return false;

    *ncpu = (uint32_t)cpus;
    return true;
}

glug_bool physical_mem_posix(uint64_t *bytes)
{
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_sz = sysconf(_SC_PAGESIZE);
    *bytes = 0;

    if (pages == -1 || pages == -1) return false;

    *bytes = (uint64_t)pages * (uint64_t)page_sz;
    return true;
}
