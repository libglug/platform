#ifndef GLUG_SYSTEM_BSD_H
#define GLUG_SYSTEM_BSD_H

#include <sys/types.h>

typedef int  (*sysctl_t)(const int *, u_int, void *, size_t *, const void *, size_t);
typedef long (*sysconf_t)(int);

uint32_t    cpus_bsd(sysctl_t sysctl);
uint32_t    active_cpus_bsd(sysconf_t);
uint64_t    physical_mem_bsd(sysctl_t sysctl);

#endif // GLUG_SYSTEM_BSD_H
