#include "system_builder.h"
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_WIN
#include "win32/system.h"

void build_system(struct glug_sys *system)
{
    system->cpu_count = cpu_count_win;
    system->active_cpus = active_cpus_win;
    system->physical_mem = physical_mem_win;
}

#endif // GLUG_OS == GLUG_OS_WIN
