#include <glug/os.h>

#if GLUG_OS == GLUG_OS_LIN

#include "platform_builder.h"
#include "linux/platform.h"
#include "posix/platform.h"

#include <dlfcn.h>

static enum glug_os get_os_linux(const plat_context *context)
{
    return os_linux(&context->lin);
}

static void get_os_version_linux(struct glug_plat_version *version, const plat_context *context)
{
    os_version_linux(version, &context->lin);
}

static void get_os_version_posix(struct glug_plat_version *version, const plat_context *context)
{
    os_version_posix(version, &context->pos);
}

static void get_kernel_version_linux(struct glug_plat_version *version, const plat_context *context)
{
    kernel_version_linux(version, &context->lin);
}

static void get_kernel_version_posix(struct glug_plat_version *version, const plat_context *context)
{
    kernel_version_posix(version, &context->pos);
}

#include <string.h>

void build_platform(struct glug_plat *platform)
{
    FILE *proc_version = NULL, *lsb_release = NULL;
    plat_context *context = &platform->plat_context;
    void *libc = dlopen(0, RTLD_NOW);

    platform->os = get_os_linux;

    if (libc)
    {
        int (*uname)(struct utsname *) = (int (*)(struct utsname *))dlsym(libc, "uname");
        if (uname)
        {
            context->pos.uname = uname;
            platform->kernel_version = get_kernel_version_posix;
        }
    }
    else if ((proc_version = fopen("/proc/version", "r")))
    {
        context->lin.proc_version = proc_version;
        platform->kernel_version = get_kernel_version_linux;
    }

    if ((lsb_release = fopen("/etc/lsb-release", "r")))
    {
        context->pos.lsb_release = lsb_release;
        platform->os_version = get_os_version_posix;
    }

    dlclose(libc);
}

void teardown_platform(struct glug_plat *platform)
{
    if (platform->plat_context.lin.proc_version)
        fclose(platform->plat_context.lin.proc_version);

    if (platform->plat_context.pos.lsb_release)
        fclose(platform->plat_context.pos.lsb_release);
}

#endif // GLUG_OS == GLUG_OS_LIN
