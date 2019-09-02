#ifndef GLUG_SYSTEM_WIN32_H
#define GLUG_SYSTEM_WIN32_H

#include <glug/bool.h>
#include <stdint.h>

glug_bool   cpu_count_win(uint32_t *);
glug_bool   active_cpus_win(uint32_t *);
glug_bool   physical_mem_win(uint64_t *);

#endif // GLUG_SYSTEM_WIN32_H
