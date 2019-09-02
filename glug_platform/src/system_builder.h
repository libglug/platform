#ifndef GLUG_SYSTEM_BUILDER_H
#define GLUG_SYSTEM_BUILDER_H

#include <glug/bool.h>
#include <stdint.h>

struct glug_sys
{
    glug_bool (*cpu_count)(uint32_t *);
    glug_bool (*active_cpus)(uint32_t *);
    glug_bool (*physical_mem)(uint64_t *);
};

void build_system(struct glug_sys *);

#endif // GLUG_SYSTEM_BUILDER_H
