#include "system_builder.h"
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_BSD
#include "bsd/system.h"
#if __POSIX_VISIBLE
#include "posix/system.h"
#endif

void build_system(struct glug_sys *system)
{
    system->cpu_count    = cpu_count_bsd;
    system->active_cpus  = active_cpus_bsd;
    system->physical_mem = physical_mem_bsd;

#if __POSIX_VISIBLE
    system->active_cpus = active_cpus_bsd() ? active_cpus_bsd : active_cpus_posix;
#endif
}

void teardown_system(struct glug_sys *system)
{
    (void) system;
}


#endif // GLUG_OS == GLUG_OS_BSD
