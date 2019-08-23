#ifndef GLUG_SYSTEM_H
#define GLUG_SYSTEM_H

#include <glug/import.h>
#include <glug/extern.h>

#include <stdint.h>

GLUG_EXTERN_START

GLUG_LIB_API unsigned int   glug_sys_cpus(void);
GLUG_LIB_API unsigned int   glug_sys_active_cpus(void);

GLUG_LIB_API uint64_t       glug_sys_mem(void);

GLUG_EXTERN_END

#endif // GLUG_SYSTEM_H
