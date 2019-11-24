#ifndef GLUG_PLATFORM_MACOS_H
#define GLUG_PLATFORM_MACOS_H

#include <glug/bool.h>
#include <glug/platform/os.h>
#include <glug/platform/version_t.h>

#include <stdio.h>

enum glug_os    os_mac(void);
void            os_version_mac(struct glug_plat_version *);
void            kernel_version_mac(struct glug_plat_version *);

glug_bool       responds_to_osversion(void);
void            os_version_fallback_mac(FILE *, struct glug_plat_version *);

#endif // GLUG_PLATFORM_MACOS_H
