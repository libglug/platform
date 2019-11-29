#ifndef GLUG_PLATFORM_LINUX_H
#define GLUG_PLATFORM_LINUX_H

#include <glug/platform/os.h>
#include <glug/platform/version_t.h>

#include <stdio.h>

struct utsname;
typedef int (*uname_t)(struct utsname *);

GLUG_LIB_LOCAL enum glug_os os_linux(void);

GLUG_LIB_LOCAL void         os_version_linux(struct glug_plat_version *);
GLUG_LIB_LOCAL void         os_version_lsb(FILE *, struct glug_plat_version *);

GLUG_LIB_LOCAL void         kernel_version_linux(FILE *, struct glug_plat_version *);
GLUG_LIB_LOCAL void         kernel_version_uname(const uname_t, struct glug_plat_version *);

#endif // GLUG_PLATFORM_LINUX_H
