#include <glug/platform/system.h>
#include "system_builder.h"

#include <stdlib.h>

glug_bool glug_sys_cpus(struct glug_sys *system, uint32_t *ncpu)
{
    return system->cpu_count(ncpu);
}

glug_bool glug_sys_active_cpus(struct glug_sys *system, uint32_t *ncpu)
{
    return system->active_cpus(ncpu);
}

glug_bool glug_sys_mem(struct glug_sys *system, uint64_t *bytes)
{
    return system->physical_mem(bytes);
}

struct glug_sys *glug_sys_init(void)
{
    struct glug_sys *sys = malloc(sizeof(struct glug_sys));
    if (sys)
        build_system(sys);

    return sys;
}
