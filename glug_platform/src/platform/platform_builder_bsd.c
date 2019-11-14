#include "platform_builder.h"
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_BSD
#include "bsd/platform.h"

static enum glug_os get_os_bsd(const struct bsd_context *context)
{
    (void) context;

    return os_bsd();
}

static void get_os_version_bsd(struct glug_plat_version *version, const struct bsd_context *context)
{
    (void) context;

    os_version_bsd(version);
}

static void get_kernel_version_bsd(struct glug_plat_version *version, const struct bsd_context *context)
{
    (void) context;

    kernel_version_bsd(version);
}

void build_platform(struct glug_plat *platform)
{
    platform->os = get_os_bsd;
    platform->os_version = get_os_version_bsd;
    platform->kernel_version = get_kernel_version_bsd;
}

void teardown_platform(struct glug_plat *platform)
{
    (void) platform;
}

#endif // GLUG_OS == GLUG_OS_BSD
