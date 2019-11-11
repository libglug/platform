#include "system_builder.h"
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_LIN
#include "linux/system.h"
#include "posix/system.h"

void build_system(struct glug_sys *system)
{
    system->cpu_count = cpu_count_posix() ? cpu_count_posix : cpu_count_linux;
    system->active_cpus = active_cpus_posix() ? active_cpus_posix : active_cpus_linux;
    system->physical_mem = physical_mem_posix() ? physical_mem_posix : physical_mem_linux;
}

#endif // GLUG_OS == GLUG_OS_LIN
