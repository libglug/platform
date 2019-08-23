#ifndef GLUG_SYSTEM_PLATFORM_H
#define GLUG_SYSTEM_PLATFORM_H

#include <stdint.h>

unsigned int cpu_count(void);
unsigned int active_cpus(void);

uint64_t physical_mem(void);

#endif // GLUG_SYSTEM_PLATFORM_H
