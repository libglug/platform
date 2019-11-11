#include <glug/platform/system.h>
#include "system_builder.h"

#include <stdlib.h>

struct glug_sys *glug_sys_create(void)
{
    struct glug_sys *sys = malloc(sizeof(struct glug_sys));
    if (sys)
        build_system(sys);

    return sys;
}

struct glug_sys *glug_sys_free(struct glug_sys *system)
{
    if (system)
        free(system);

    return NULL;
}

uint32_t glug_sys_cpus(struct glug_sys *system)
{
    uint32_t ncpu = system->cpu_count();
    return ncpu;
}

uint32_t glug_sys_active_cpus(struct glug_sys *system)
{
    uint32_t ncpu = system->active_cpus();
    return ncpu;
}

uint64_t glug_sys_mem(struct glug_sys *system)
{
    uint64_t bytes = system->physical_mem();
    return bytes;
}
