#ifndef GLUG_PLATFORM_MACOS_H
#define GLUG_PLATFORM_MACOS_H

#include <glug/bool.h>
#include <glug/platform/os.h>
#include <glug/platform/version.h>

enum glug_os    os_mac(void);
glug_bool       os_version_mac(struct glug_plat_version *);
glug_bool       kernel_version_mac(struct glug_plat_version *);

#endif // GLUG_PLATFORM_MACOS_H
