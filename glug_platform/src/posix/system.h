#ifndef GLUG_SYSTEM_POSIX_H
#define GLUG_SYSTEM_POSIX_H

#include <glug/bool.h>
#include <stdint.h>

bool    (*get_cpu_count_posix(void))(uint32_t *);
bool    (*get_active_cpus_posix(void))(uint32_t *);
bool    (*get_physical_mem_posix(void))(uint64_t *);

#endif // GLUG_SYSTEM_POSIX_H
