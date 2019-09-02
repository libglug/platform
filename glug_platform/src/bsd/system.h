#ifndef GLUG_SYSTEM_BSD_H
#define GLUG_SYSTEM_BSD_H

#include <glug/bool.h>
#include <stdint.h>

glug_bool   cpu_count_bsd(uint32_t *);
glug_bool   active_cpus_bsd(uint32_t *);
glug_bool   physical_mem_bsd(uint64_t *);

#endif // GLUG_SYSTEM_BSD_H
