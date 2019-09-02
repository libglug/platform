#ifndef GLUG_SYSTEM_POSIX_H
#define GLUG_SYSTEM_POSIX_H

#include <glug/bool.h>
#include <stdint.h>

glug_bool    cpu_count_posix(uint32_t *);
glug_bool    active_cpus_posix(uint32_t *);
glug_bool    physical_mem_posix(uint64_t *);

#endif // GLUG_SYSTEM_POSIX_H
