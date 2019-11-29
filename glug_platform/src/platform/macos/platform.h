#ifndef GLUG_PLATFORM_MACOS_H
#define GLUG_PLATFORM_MACOS_H

#include <glug/bool.h>
#include <glug/platform/os.h>
#include <glug/platform/version_t.h>

#include <stdio.h>

GLUG_LIB_LOCAL enum glug_os os_mac(void);
GLUG_LIB_LOCAL void         os_version_mac(struct glug_plat_version *);
GLUG_LIB_LOCAL void         kernel_version_mac(struct glug_plat_version *);

GLUG_LIB_LOCAL glug_bool    responds_to_osversion(void);
GLUG_LIB_LOCAL void         os_version_fallback_mac(FILE *, struct glug_plat_version *);

#endif // GLUG_PLATFORM_MACOS_H
