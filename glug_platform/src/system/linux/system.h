#ifndef GLUG_SYSTEM_LINUX_H
#define GLUG_SYSTEM_LINUX_H

#include <glug/bool.h>
#include <stdio.h>
#include <stdint.h>

uint32_t    cpus_linux(FILE *);
uint32_t    active_cpus_linux(FILE *);
uint64_t    physical_mem_linux(FILE *);

#endif // GLUG_SYSTEM_LINUX_H
