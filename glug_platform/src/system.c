#include <glug/platform/system.h>
#include "system_platform.h"

#include <stdlib.h>

uint32_t glug_sys_cpus(struct glug_sys *system)
{
    return system->cpu_count();
}

uint32_t glug_sys_active_cpus(struct glug_sys *system)
{
    return system->active_cpus();
}

uint64_t glug_sys_mem(struct glug_sys *system)
{
    return system->physical_mem();
}

struct glug_sys *glug_sys_init()
{
    struct glug_sys *sys = malloc(sizeof(struct glug_sys));

    sys->cpu_count = get_cpu_count_fcn();
    sys->active_cpus = get_active_cpus_fcn();
    sys->physical_mem = get_physical_mem_fcn();

    return sys;
}
