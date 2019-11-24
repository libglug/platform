#include "platform_builder.h"
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_LIN
#include "linux/platform.h"

#include <dlfcn.h>

void build_platform(struct glug_plat *platform)
{
    void *libc;

    // os version
    platform->lsb_release = fopen("/etc/lsb-release", "r");

    // kernel version
    libc = dlopen(0, RTLD_NOW);
    if (libc)
    {
        void *uname = dlsym(platform->libc, "uname");

        platform->libc = libc;
        platform->uname = (uname_t)uname;
    }

    platform->proc_version = fopen("/proc/version", "r");
}

void teardown_platform(struct glug_plat *platform)
{
    if (platform)
    {
        if (platform->libc)
            dlclose(platform->libc);

        if (platform->proc_version)
            fclose(platform->proc_version);

        if (platform->lsb_release)
            fclose(platform->lsb_release);
    }
}

enum glug_os os_plat(const struct glug_plat *platform)
{
    (void) platform;

    return os_linux();
}

void os_version_plat(const struct glug_plat *platform, struct glug_plat_version *version)
{
    if (version)
        if (platform->lsb_release)
            os_version_lsb(platform->lsb_release, version);
}

void kernel_version_plat(const struct glug_plat *platform, struct glug_plat_version *version)
{
    if (version)
    {
        if (platform->uname)
            kernel_version_uname(platform->uname, version);
        else if (platform->proc_version)
            kernel_version_linux(platform->proc_version, version);
    }
}

#endif // GLUG_OS == GLUG_OS_LIN
