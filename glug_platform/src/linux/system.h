#ifndef GLUG_SYSTEM_LINUX_H
#define GLUG_SYSTEM_LINUX_H

#include <glug/bool.h>
#include <stdint.h>

glug_bool   cpu_count_linux(uint32_t *);
glug_bool   active_cpus_linux(uint32_t *);
glug_bool   physical_mem_linux(uint64_t *);

#endif // GLUG_SYSTEM_LINUX_H
