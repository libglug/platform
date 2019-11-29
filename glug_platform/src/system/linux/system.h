#ifndef GLUG_SYSTEM_LINUX_H
#define GLUG_SYSTEM_LINUX_H

#include <glug/bool.h>
#include <stdio.h>
#include <stdint.h>

GLUG_LIB_LOCAL uint32_t cpus_linux(FILE *);
GLUG_LIB_LOCAL uint32_t active_cpus_linux(FILE *);
GLUG_LIB_LOCAL uint64_t physical_mem_linux(FILE *);

#endif // GLUG_SYSTEM_LINUX_H
