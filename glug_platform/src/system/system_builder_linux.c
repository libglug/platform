#include "system_builder.h"
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_LIN
#include "linux/system.h"

#include <stdio.h>
#include <dlfcn.h>

void build_system(struct glug_sys *system)
{
    system->sys_cpu_pres = fopen("/sys/devices/system/cpu/present", "r");
    system->sys_cpu_onln = fopen("/sys/devices/system/cpu/online", "r");
    system->proc_meminfo = fopen("/proc/meminfo", "r");
}

void teardown_system(struct glug_sys *system)
{
    if (system)
    {
        if (system->sys_cpu_pres)
            fclose(system->sys_cpu_pres);

        if (system->sys_cpu_onln)
            fclose(system->sys_cpu_onln);

        if (system->proc_meminfo)
            fclose(system->proc_meminfo);
    }
}

uint32_t cpus_plat(const struct glug_sys *system)
{
    if (system && system->sys_cpu_pres)
        return cpus_linux(system->sys_cpu_pres);

    return 0;
}

uint32_t active_cpus_plat(const struct glug_sys *system)
{
    if (system && system->sys_cpu_onln)
        return active_cpus_linux(system->sys_cpu_onln);

    return 0;
}

uint64_t physical_mem_plat(const struct glug_sys *system)
{
    if (system && system->proc_meminfo)
        return physical_mem_linux(system->proc_meminfo);

    return 0;
}

#endif // GLUG_OS == GLUG_OS_LIN
