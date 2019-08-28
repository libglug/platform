#include "../platform_platform.h"

static int os(void)
{
    return glug_os_linux;
}

static int os_version(struct glug_plat_version *version)
{
    // TODO: set version
}

static int kernel_version(struct glug_plat_version *version)
{

}

enum glug_os (*get_os_linux(void))(void)
{
    return os;
}

int (*get_os_version_linux(void))(struct glug_plat_version *)
{
    return os_version;
}

int (*get_kernel_version_linux(void))(struct glug_plat_version *)
{
    return kernel_version;
}
