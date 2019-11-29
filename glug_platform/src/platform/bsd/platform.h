#ifndef GLUG_PLATFORM_BSD_H
#define GLUG_PLATFORM_BSD_H

#include <glug/platform/os.h>
#include <glug/platform/version_t.h>

#include <sys/types.h>

typedef int (*sysctl_t)(const int *name, u_int namelen,
                        void *oldp, size_t *oldlenp,
                        const void *newp, size_t newlen);

GLUG_LIB_LOCAL enum glug_os os_bsd(void);
GLUG_LIB_LOCAL void         os_version_bsd(sysctl_t, struct glug_plat_version *);
GLUG_LIB_LOCAL void         kernel_version_bsd(sysctl_t, struct glug_plat_version *);

#endif // GLUG_PLATFORM_BSD_H
