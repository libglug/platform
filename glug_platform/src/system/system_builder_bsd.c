#include "system_builder.h"
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_BSD
#include "bsd/system.h"

#include <dlfcn.h>

void build_system(struct glug_sys *system)
{
    void *libc = dlopen(NULL, RTLD_NOW);

    if (libc)
    {
        void *sysctl  = dlsym(libc, "sysctl");
        void *sysconf = dlsym(libc, "sysconf");

        system->libc = libc;
        system->sysctl = (sysctl_t)sysctl;
        system->sysconf = (sysconf_t)sysconf;
    }
}

void teardown_system(struct glug_sys *system)
{
    if (system)
    {
        if (system->libc)
            dlclose(system->libc);
    }
}

uint32_t cpus_plat(const struct glug_sys *system)
{
    if (system && system->sysctl)
        return cpus_bsd(system->sysctl);

    return 0;
}

uint32_t active_cpus_plat(const struct glug_sys *system)
{
    if (system && system->sysconf)
        return active_cpus_bsd(system->sysconf);

    return 0;
}

uint64_t physical_mem_plat(const struct glug_sys *system)
{
    if (system && system->sysctl)
        return physical_mem_bsd(system->sysctl);

    return 0;
}

#endif // GLUG_OS == GLUG_OS_BSD
