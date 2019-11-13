#include <glug/platform/system.h>
#include "system_builder.h"
#include "null/system.h"

#include <stdlib.h>

static uint32_t get_cpu_count(const sys_context *context)
{
    (void) context;

    return cpu_count_null();
}

static uint32_t get_active_cpus(const sys_context *context)
{
    (void) context;

    return active_cpus_null();
}

static uint64_t get_physical_mem(const sys_context *context)
{
    (void) context;

    return physical_mem_null();
}

struct glug_sys *glug_sys_create(void)
{
    struct glug_sys *sys = malloc(sizeof(struct glug_sys));
    if (sys)
    {
        sys->cpu_count = get_cpu_count;
        sys->active_cpus = get_active_cpus;
        sys->physical_mem = get_physical_mem;
        build_system(sys);
    }

    return sys;
}

struct glug_sys *glug_sys_free(struct glug_sys *system)
{
    teardown_system(system);
    if (system)
        free(system);

    return NULL;
}

uint32_t glug_sys_cpus(struct glug_sys *system)
{
    return system->cpu_count(&system->context);
}

uint32_t glug_sys_active_cpus(struct glug_sys *system)
{
    return system->active_cpus(&system->context);
}

uint64_t glug_sys_mem(struct glug_sys *system)
{
    return system->physical_mem(&system->context);
}
