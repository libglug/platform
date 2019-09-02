#include "system_builder.h"

#include <glug/os.h>

#if defined(GLUG_OS_WIN)

#include "win32/system.h"

void build_system(struct glug_sys *system)
{
    system->cpu_count = cpu_count_win;
    system->active_cpus = active_cpus_win;
    system->physical_mem = physical_mem_win;
}
#elif defined(GLUG_OS_MAC)

#include "macos/system.h"

void build_system(struct glug_sys *system)
{
    system->cpu_count = cpu_count_mac;
    system->active_cpus = active_cpus_mac;
    system->physical_mem = physical_mem_mac;
}

#elif defined(GLUG_OS_LIN)

#include "linux/system.h"
#include "posix/system.h"

void build_system(struct glug_sys *system)
{
    uint32_t tmp;
    uint64_t ltmp;

    system->cpu_count = cpu_count_posix(&tmp) ? cpu_count_posix : cpu_count_linux;
    system->active_cpus = active_cpus_posix(&tmp) ? active_cpus_posix : active_cpus_linux;
    system->physical_mem = physical_mem_posix(&ltmp) ? physical_mem_posix : physical_mem_linux;
}

#elif defined(GLUG_OS_BSD)

#include "bsd/system.h"
#if __POSIX_VISIBLE
#include "posix/system.h"
#endif

void build_system(struct glug_sys *system)
{
    uint32_t tmp = 0;

    system->cpu_count = cpu_count_bsd;
    system->active_cpus = active_cpus_bsd;
    system->physical_mem = physical_mem_bsd;

#if __POSIX_VISIBLE
    system->active_cpus = active_cpus_bsd(&tmp) ? active_cpus_bsd : active_cpus_posix;
#endif
}

#endif
