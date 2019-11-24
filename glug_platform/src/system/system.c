#include <glug/platform/system.h>
#include "system_builder.h"
#include "null/system.h"

#include <stdlib.h>

struct glug_sys *glug_sys_create(void)
{
    struct glug_sys *sys = calloc(1, sizeof(struct glug_sys));
    if (sys)
        build_system(sys);

    return sys;
}

struct glug_sys *glug_sys_free(struct glug_sys *system)
{
    if (system)
    {
        teardown_system(system);
        free(system);
    }

    return NULL;
}

uint32_t glug_sys_cpus(struct glug_sys *system)
{
    return cpus_plat(system);
}

uint32_t glug_sys_active_cpus(struct glug_sys *system)
{
    return active_cpus_plat(system);
}

uint64_t glug_sys_mem(struct glug_sys *system)
{
    return physical_mem_plat(system);
}
