#ifndef GLUG_SYSTEM_WIN32_H
#define GLUG_SYSTEM_WIN32_H

#include <stdint.h>

uint32_t    cpu_count_win(void);
uint32_t    active_cpus_win(void);
uint64_t    physical_mem_win(void);

#endif // GLUG_SYSTEM_WIN32_H
