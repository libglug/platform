#include "platform_builder.h"
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_BSD
#include "bsd/platform.h"
#include <dlfcn.h>


void build_platform(struct glug_plat *platform)
{
    void *libc = dlopen(0, RTLD_NOW);

    if (libc)
    {
        sysctl_t sysctl = (sysctl_t)dlsym(libc, "sysctl");
        if (sysctl)
        {
            platform->libc   = libc;
            platform->sysctl = sysctl;
        }
    }
}

void teardown_platform(struct glug_plat *platform)
{
    if (platform)
    {
        if (platform->libc)
            dlclose(platform->libc);
    }
}

enum glug_os os_plat(const struct glug_plat *platform)
{
    (void) platform;

    return os_bsd();
}

void os_version_plat(const struct glug_plat *platform, struct glug_plat_version *version)
{
    if (version && platform && platform->sysctl)
        os_version_bsd(platform->sysctl, version);
}

void kernel_version_plat(const struct glug_plat *platform, struct glug_plat_version *version)
{
    if (version && platform && platform->sysctl)
        kernel_version_bsd(platform->sysctl, version);
}

#endif // GLUG_OS == GLUG_OS_BSD
