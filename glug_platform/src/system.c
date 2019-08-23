#include <glug/platform/system.h>
#include "system_platform.h"

unsigned int glug_sys_cpus(void)
{
    return cpu_count();
}

unsigned int glug_sys_active_cpus()
{
    return active_cpus();
}

uint64_t glug_sys_mem(void)
{
    return physical_mem();
}
