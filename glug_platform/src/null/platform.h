#ifndef GLUG_PLATFORM_NULL_H
#define GLUG_PLATFORM_NULL_H

#include <glug/bool.h>
#include <glug/platform/os.h>
#include <glug/platform/version.h>

enum glug_os    os_null(void);
glug_bool       os_version_null(struct glug_plat_version *);
glug_bool       kernel_version_null(struct glug_plat_version *);

#endif // GLUG_PLATFORM_NULL_H
