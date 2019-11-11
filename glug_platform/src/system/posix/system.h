#ifndef GLUG_SYSTEM_POSIX_H
#define GLUG_SYSTEM_POSIX_H

#include <stdint.h>

uint32_t    cpu_count_posix(void);
uint32_t    active_cpus_posix(void);
uint64_t    physical_mem_posix(void);

#endif // GLUG_SYSTEM_POSIX_H
