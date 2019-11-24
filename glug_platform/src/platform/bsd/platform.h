#ifndef GLUG_PLATFORM_BSD_H
#define GLUG_PLATFORM_BSD_H

#include <glug/platform/os.h>
#include <glug/platform/version_t.h>

#include <sys/types.h>

typedef int (*sysctl_t)(const int *name, u_int namelen, void *oldp, size_t *oldlenp, const void *newp, size_t newlen);

enum glug_os    os_bsd(void);
void            os_version_bsd(sysctl_t, struct glug_plat_version *);
void            kernel_version_bsd(sysctl_t, struct glug_plat_version *);

#endif // GLUG_PLATFORM_BSD_H
