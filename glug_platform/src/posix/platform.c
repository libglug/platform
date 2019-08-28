#include "../platform_platform.h"

static enum glug_os os(void)
{
    return glug_os_linux;
}

static bool os_version(struct glug_plat_version *version)
{
    // TODO: set version
}

static bool kernel_version(struct glug_plat_version *version)
{

}

enum glug_os (*get_os_posix(void))(void)
{
    return os;
}

int (*get_os_version_posix(void))(struct glug_plat_version *)
{
    return os_version;
}

int (*get_kernel_version_posix(void))(struct glug_plat_version *)
{
    return kernel_version;
}
