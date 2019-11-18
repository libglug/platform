#include "platform_builder.h"
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_BSD
#include "bsd/platform.h"
#include <dlfcn.h>

static enum glug_os get_os_bsd(const struct bsd_context *context)
{
    (void) context;

    return os_bsd();
}

void build_platform(struct glug_plat *platform)
{
    plat_context *context = &platform->plat_context;
    void *libc = dlopen(0, RTLD_NOW);

    platform->os = get_os_bsd;

    if (libc)
    {
        sysctl_t sysctl = (sysctl_t)dlsym(libc, "sysctl");
        if (sysctl)
        {
            context->sysctl = sysctl;
            platform->os_version = os_version_bsd;
            platform->kernel_version = kernel_version_bsd;
        }
    }

    dlclose(libc);
}

void teardown_platform(struct glug_plat *platform)
{
    (void) platform;
}

#endif // GLUG_OS == GLUG_OS_BSD
