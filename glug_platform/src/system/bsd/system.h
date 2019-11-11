#ifndef GLUG_SYSTEM_BSD_H
#define GLUG_SYSTEM_BSD_H

#include <stdint.h>

uint32_t    cpu_count_bsd(void);
uint32_t    active_cpus_bsd(void);
uint64_t    physical_mem_bsd(void);

#endif // GLUG_SYSTEM_BSD_H
