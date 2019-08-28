#ifndef GLUG_SYSTEM_LINUX_H
#define GLUG_SYSTEM_LINUX_H

#include <glug/bool.h>
#include <stdint.h>

bool    (*get_cpu_count_linux(void))(uint32_t *);
bool    (*get_active_cpus_linux(void))(uint32_t *);
bool    (*get_physical_mem_linux(void))(uint64_t *);

#endif // GLUG_SYSTEM_LINUX_H
