#ifndef GLUG_SYSTEM_BUILDER_H
#define GLUG_SYSTEM_BUILDER_H

#include <glug/bool.h>
#include <stdint.h>

struct glug_sys
{
    uint32_t (*cpu_count)(void);
    uint32_t (*active_cpus)(void);
    uint64_t (*physical_mem)(void);
};

void build_system(struct glug_sys *);

#endif // GLUG_SYSTEM_BUILDER_H
