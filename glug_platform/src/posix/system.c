#include "../system_platform.h"

#include <unistd.h>

static bool cpu_count(uint32_t *ncpu)
{
    long cpus = sysconf(_SC_NPROCESSORS_CONF);
    *ncpu = 0;

    if (cpus == -1) return false;

    *ncpu = (uint32_t)cpus;
    return true;
}

static bool active_cpus(uint32_t *ncpu)
{
    long cpus = sysconf(_SC_NPROCESSORS_ONLN);
    *ncpu = 0;

    if (cpus == -1) return false;

    *ncpu = (uint32_t)cpus;
    return true;
}

static bool physical_memory(uint64_t *bytes)
{
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_sz = sysconf(_SC_PAGESIZE);
    *bytes = 0;

    if (pages == -1 || pages == -1) return false;

    *bytes = (uint64_t)pages * (uint64_t)page_sz;
    return true;
}

bool (*get_cpu_count_posix(void))(uint32_t *)
{
    return cpu_count;
}

bool (*get_active_cpus_posix(void))(uint32_t *)
{
    return active_cpus;
}

bool (*get_physical_mem_posix(void))(uint64_t *)
{
    return physical_memory;
}
