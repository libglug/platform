#ifndef BSD_PLATFORM_CONTEXT_H
#define BSD_PLATFORM_CONTEXT_H

#include <sys/types.h>

typedef int (*sysctl_t)(const int *name, u_int namelen, void *oldp, size_t *oldlenp, const void *newp, size_t newlen);

struct bsd_context
{
    sysctl_t sysctl;
};

#endif // BSD_PLATFORM_CONTEXT_H
