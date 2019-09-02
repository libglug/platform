#ifndef GLUG_PLATFORM_LINUX_H
#define GLUG_PLATFORM_LINUX_H

#include <glug/platform/os.h>
#include <glug/platform/version.h>

#include <glug/bool.h>

enum glug_os    os_linux(void);
glug_bool       os_version_linux(struct glug_plat_version *);
glug_bool       kernel_version_linux(struct glug_plat_version *);

#endif // GLUG_PLATFORM_LINUX_H
