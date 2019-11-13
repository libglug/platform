#include "system_builder.h"
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_MAC
#include "macos/system.h"

static uint32_t get_cpu_count_mac(const sys_context *context)
{
    (void) context;

    return cpu_count_mac();
}

static uint32_t get_active_cpus_mac(const sys_context *context)
{
    (void) context;

    return active_cpus_mac();
}

static uint64_t get_physical_mem_mac(const sys_context *context)
{
    (void) context;

    return physical_mem_mac();
}

void build_system(struct glug_sys *system)
{
    system->cpu_count    = get_cpu_count_mac;
    system->active_cpus  = get_active_cpus_mac;
    system->physical_mem = get_physical_mem_mac;
}

void teardown_system(struct glug_sys *system)
{
    (void) system;
}

#endif // GLUG_OS == GLUG_OS_MAC
