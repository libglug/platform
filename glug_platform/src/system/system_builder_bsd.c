#include "system_builder.h"
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_BSD
#include "bsd/system.h"

static uint32_t get_cpu_count_bsd(const sys_context *context)
{
    (void) context;

    return cpu_count_bsd();
}

static uint32_t get_active_cpus_bsd(const sys_context *context)
{
    (void) context;

    return active_cpus_bsd();
}

static uint64_t get_physical_mem_bsd(const sys_context *context)
{
    (void) context;

    return physical_mem_bsd();
}


void build_system(struct glug_sys *system)
{
    system->cpu_count    = get_cpu_count_bsd;
    system->active_cpus  = get_active_cpus_bsd;
    system->physical_mem = get_physical_mem_bsd;
}

void teardown_system(struct glug_sys *system)
{
    (void) system;
}


#endif // GLUG_OS == GLUG_OS_BSD
