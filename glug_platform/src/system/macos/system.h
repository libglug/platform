#ifndef GLUG_SYSTEM_MACOS_H
#define GLUG_SYSTEM_MACOS_H

#include <stdint.h>

GLUG_LIB_LOCAL uint32_t cpus_mac(void);
GLUG_LIB_LOCAL uint32_t active_cpus_mac(void);
GLUG_LIB_LOCAL uint64_t physical_mem_mac(void);

#endif // GLUG_SYSTEM_MACOS_H
