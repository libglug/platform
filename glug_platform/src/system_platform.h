#ifndef GLUG_SYSTEM_PLATFORM_H
#define GLUG_SYSTEM_PLATFORM_H

#include <stdint.h>

struct glug_sys
{
    uint32_t (*cpu_count)(void);
    uint32_t (*active_cpus)(void);
    uint64_t (*physical_mem)(void);
};

uint32_t    (*get_cpu_count_fcn(void))(void);
uint32_t    (*get_active_cpus_fcn(void))(void);
uint64_t    (*get_physical_mem_fcn(void))(void);

#endif // GLUG_SYSTEM_PLATFORM_H
