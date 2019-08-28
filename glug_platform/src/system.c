#include <glug/platform/system.h>
#include "system_platform.h"

#include <stdlib.h>

bool glug_sys_cpus(struct glug_sys *system, uint32_t *ncpu)
{
    return system->cpu_count(ncpu);
}

bool glug_sys_active_cpus(struct glug_sys *system, uint32_t *ncpu)
{
    return system->active_cpus(ncpu);
}

bool glug_sys_mem(struct glug_sys *system, uint64_t *bytes)
{
    return system->physical_mem(bytes);
}

struct glug_sys *glug_sys_init()
{
    struct glug_sys *sys = malloc(sizeof(struct glug_sys));

    sys->cpu_count = get_cpu_count_fcn();
    sys->active_cpus = get_active_cpus_fcn();
    sys->physical_mem = get_physical_mem_fcn();

    return sys;
}
