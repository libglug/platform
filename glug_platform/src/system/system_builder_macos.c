#include "system_builder.h"
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_MAC
#include "macos/system.h"

void build_system(struct glug_sys *system)
{
    system->cpu_count = cpu_count_mac;
    system->active_cpus = active_cpus_mac;
    system->physical_mem = physical_mem_mac;
}

#endif // GLUG_OS == GLUG_OS_MAC
