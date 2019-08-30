#ifndef GLUG_SYSTEM_WIN32_H
#define GLUG_SYSTEM_WIN32_H

#include <glug/bool.h>
#include <stdint.h>

bool    (*get_cpu_count_win(void))(uint32_t *);
bool    (*get_active_cpus_win(void))(uint32_t *);
bool    (*get_physical_mem_win(void))(uint64_t *);

#endif // GLUG_SYSTEM_WIN32_H
