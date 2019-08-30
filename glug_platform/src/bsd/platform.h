#ifndef GLUG_PLATFORM_BSD_H
#define GLUG_PLATFORM_BSD_H

#include <glug/platform/os.h>
#include <glug/platform/version.h>

#include <glug/bool.h>

enum glug_os    (*get_os_bsd(void))(void);
bool            (*get_os_version_bsd(void))(struct glug_plat_version *);
bool            (*get_kernel_version_bsd(void))(struct glug_plat_version *);

#endif // GLUG_PLATFORM_BSD_H
