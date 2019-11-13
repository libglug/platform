#include "system_builder.h"
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_WIN
#include "win32/system.h"

static uint32_t get_cpu_count_win(const sys_context *context)
{
    (void) context;

    return cpu_count_win();
}

static uint32_t get_active_cpus_win(const sys_context *context)
{
    (void) context;

    return active_cpus_win();
}

static uint64_t get_physical_mem_win(const sys_context *context)
{
    (void) context;

    return physical_mem_win();
}

void build_system(struct glug_sys *system)
{
    system->cpu_count    = get_cpu_count_win;
    system->active_cpus  = get_active_cpus_win;
    system->physical_mem = get_physical_mem_win;
}

void teardown_system(struct glug_sys *system)
{
    (void) system;
}

#endif // GLUG_OS == GLUG_OS_WIN
