#include "system_builder.h"
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_UNK
#include "null/system.h"

static uint32_t get_cpu_count_null(const sys_context *context)
{
    (void) context;

    return cpu_count_null();
}

static uint32_t get_active_cpus_null(const sys_context *context)
{
    (void) context;

    return active_cpus_null();
}

static uint64_t get_physical_mem_null(const sys_context *context)
{
    (void) context;

    return physical_mem_null();
}

void build_system(struct glug_sys *system)
{
    system->cpu_count    = get_cpu_count_null;
    system->active_cpus  = get_active_cpus_null;
    system->physical_mem = get_physical_mem_null;
}

void teardown_system(struct glug_sys *system)
{
    (void) system;
}

#endif // GLUG_OS == GLUG_OS_NULL
