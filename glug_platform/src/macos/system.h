#ifndef GLUG_SYSTEM_MACOS_H
#define GLUG_SYSTEM_MACOS_H

#include <glug/bool.h>
#include <stdint.h>

bool    (*get_cpu_count_mac(void))(uint32_t *);
bool    (*get_active_cpus_mac(void))(uint32_t *);
bool    (*get_physical_mem_mac(void))(uint64_t *);

#endif // GLUG_SYSTEM_MACOS_H
