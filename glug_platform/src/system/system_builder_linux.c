#include "system_builder.h"
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_LIN
#include "linux/system.h"
#include "posix/system.h"

static uint32_t get_cpu_count_linux(const sys_context *context)
{
    (void) context;

    return cpu_count_linux();
}

static uint32_t get_cpu_count_posix(const sys_context *context)
{
    (void) context;

    return cpu_count_posix();
}

static uint32_t get_active_cpus_linux(const sys_context *context)
{
    (void) context;

    return active_cpus_linux();
}

static uint32_t get_active_cpus_posix(const sys_context *context)
{
    (void) context;

    return active_cpus_posix();
}

static uint64_t physical_mem_get_linux(const sys_context *context)
{
    (void) context;

    return physical_mem_linux();
}

static uint64_t physical_mem_get_posix(const sys_context *context)
{
    (void) context;

    return physical_mem_posix();
}

void build_system(struct glug_sys *system)
{
    system->cpu_count    = cpu_count_posix() ? get_cpu_count_posix : get_cpu_count_linux;
    system->active_cpus  = active_cpus_posix() ? get_active_cpus_posix : get_active_cpus_linux;
    system->physical_mem = physical_mem_posix() ? physical_mem_get_posix : physical_mem_get_linux;
}

void teardown_system(struct glug_sys *system)
{
    (void) system;
}


#endif // GLUG_OS == GLUG_OS_LIN
