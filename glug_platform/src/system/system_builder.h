#ifndef GLUG_SYSTEM_BUILDER_H
#define GLUG_SYSTEM_BUILDER_H

#include <glug/bool.h>
#include <glug/os.h>
#include <stdint.h>

#if GLUG_OS == GLUG_OS_WIN

#include "win32/system.h"
struct glug_sys
{
    HANDLE          ntdll;
    GetNSInfo_t     get_native_sysinfo;
    GetPISMemory_t  get_phys_memory;
};

#elif GLUG_OS == GLUG_OS_MAC

#include "macos/system.h"
struct glug_sys
{
    void *_unused;
};

#elif GLUG_OS == GLUG_OS_LIN

#include <stdio.h>
struct glug_sys
{
    FILE *proc_meminfo;
    FILE *sys_cpu_pres;
    FILE *sys_cpu_onln;
};

#elif GLUG_OS == GLUG_OS_BSD

#include "bsd/system.h"
struct glug_sys
{
    void     *libc;
    sysctl_t  sysctl;
    sysconf_t sysconf;
};

#elif GLUG_OS == GLUG_OS_UNK

struct glug_sys
{
    void *_unused;
};

#endif

GLUG_LIB_LOCAL void build_system(struct glug_sys *);
GLUG_LIB_LOCAL void teardown_system(struct glug_sys *);

GLUG_LIB_LOCAL uint32_t cpus_plat(const struct glug_sys *);
GLUG_LIB_LOCAL uint32_t active_cpus_plat(const struct glug_sys *);
GLUG_LIB_LOCAL uint64_t physical_mem_plat(const struct glug_sys *);

#endif // GLUG_SYSTEM_BUILDER_H
