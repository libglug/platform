#include "platform.h"

enum glug_os os_posix(void)
{
    return glug_os_linux;
}

glug_bool os_version_posix(struct glug_plat_version *version)
{
    // TODO: set version
}

glug_bool kernel_version_posix(struct glug_plat_version *version)
{

}
