#ifndef GLUG_SYSTEM_LINUX_H
#define GLUG_SYSTEM_LINUX_H

#include <stdint.h>

uint32_t    cpu_count_linux(void);
uint32_t    active_cpus_linux(void);
uint64_t    physical_mem_linux(void);

#endif // GLUG_SYSTEM_LINUX_H
