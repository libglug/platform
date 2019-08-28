#ifndef GLUG_SYSTEM_H
#define GLUG_SYSTEM_H

#include <glug/import.h>
#include <glug/extern.h>

#include <stdint.h>

GLUG_EXTERN_START

struct glug_sys;
GLUG_LIB_API struct glug_sys *  glug_sys_init(void);

GLUG_LIB_API unsigned int       glug_sys_cpus(struct glug_sys *);
GLUG_LIB_API unsigned int       glug_sys_active_cpus(struct glug_sys *);

GLUG_LIB_API uint64_t           glug_sys_mem(struct glug_sys *);

GLUG_EXTERN_END

#endif // GLUG_SYSTEM_H
