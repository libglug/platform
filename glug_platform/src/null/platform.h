#ifndef GLUG_PLATFORM_NULL_H
#define GLUG_PLATFORM_NULL_H

#include <glug/bool.h>
#include <glug/platform/os.h>
#include <glug/platform/version_t.h>

enum glug_os    os_null(const void *);
glug_bool       os_version_null(struct glug_plat_version *, const void *);
glug_bool       kernel_version_null(struct glug_plat_version *, const void *);

#endif // GLUG_PLATFORM_NULL_H
