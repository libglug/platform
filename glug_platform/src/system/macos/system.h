#ifndef GLUG_SYSTEM_MACOS_H
#define GLUG_SYSTEM_MACOS_H

#include <stdint.h>

uint32_t    cpu_count_mac(void);
uint32_t    active_cpus_mac(void);
uint64_t    physical_mem_mac(void);

#endif // GLUG_SYSTEM_MACOS_H
