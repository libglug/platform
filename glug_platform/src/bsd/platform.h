#ifndef GLUG_PLATFORM_BSD_H
#define GLUG_PLATFORM_BSD_H

#include <glug/platform/os.h>
#include <glug/platform/version.h>

#include <glug/bool.h>

enum glug_os    os_bsd(void);
glug_bool       os_version_bsd(struct glug_plat_version *);
glug_bool       kernel_version_bsd(struct glug_plat_version *);

#endif // GLUG_PLATFORM_BSD_H
