#ifndef GLUG_PLATFORM_PLATFORM_H
#define GLUG_PLATFORM_PLATFORM_H

#include <glug/platform/version.h>

int os_version(struct glug_plat_version *version);
int kernel_version(struct glug_plat_version *);

#endif // GLUG_PLATFORM_PLATFORM_H
