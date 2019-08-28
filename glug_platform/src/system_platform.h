#ifndef GLUG_SYSTEM_PLATFORM_H
#define GLUG_SYSTEM_PLATFORM_H

#include <glug/bool.h>
#include <stdint.h>

struct glug_sys
{
    bool (*cpu_count)(uint32_t *);
    bool (*active_cpus)(uint32_t *);
    bool (*physical_mem)(uint64_t *);
};

extern bool (*(*get_cpu_count_fcn)(void))(uint32_t *);
extern bool (*(*get_active_cpus_fcn)(void))(uint32_t *);
extern bool (*(*get_physical_mem_fcn)(void))(uint64_t *);

#endif // GLUG_SYSTEM_PLATFORM_H
