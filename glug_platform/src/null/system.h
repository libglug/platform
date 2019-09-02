#ifndef GLUG_SYSTEM_NULL_H
#define GLUG_SYSTEM_NULL_H

#include <glug/bool.h>
#include <stdint.h>

glug_bool   cpu_count_null(uint32_t *);
glug_bool   active_cpus_null(uint32_t *);
glug_bool   physical_mem_null(uint64_t *);

#endif // GLUG_SYSTEM_NULL_H
