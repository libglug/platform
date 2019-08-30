#ifndef GLUG_PLATFORM_PLATFORM_H
#define GLUG_PLATFORM_PLATFORM_H

#include <glug/platform/os.h>
#include <glug/platform/version.h>

#include <glug/bool.h>

struct glug_plat
{
    enum glug_os (*os)(void);
    bool         (*os_version)(struct glug_plat_version *);
    bool         (*kernel_version)(struct glug_plat_version *);
};

extern enum glug_os    (*(*get_os_fcn)(void))(void);
extern bool            (*(*get_os_version_fcn)(void))(struct glug_plat_version *);
extern bool            (*(*get_kernel_version_fcn)(void))(struct glug_plat_version *);

#endif // GLUG_PLATFORM_PLATFORM_H
