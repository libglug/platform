#ifndef GLUG_SYSTEM_BSD_H
#define GLUG_SYSTEM_BSD_H

#include <stdint.h>

uint32_t    (*get_cpu_count_bsd(void))(void);
uint32_t    (*get_active_cpus_bsd(void))(void);
uint64_t    (*get_physical_mem_bsd(void))(void);

#endif // GLUG_SYSTEM_BSD_H
