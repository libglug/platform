#include "system_builder.h"
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_UNK
#include "null/system.h"

void build_system(struct glug_sys *system)
{
    system->cpu_count = cpu_count_null;
    system->active_cpus = active_cpus_null;
    system->physical_mem = physical_mem_null;
}

#endif // GLUG_OS == GLUG_OS_NULL
