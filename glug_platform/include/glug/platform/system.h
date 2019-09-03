#ifndef GLUG_SYSTEM_H
#define GLUG_SYSTEM_H

#include <glug/import.h>
#include <glug/extern.h>
#include <glug/bool.h>

#include <glug/platform/system_t.h>
#include <stdint.h>

GLUG_EXTERN_START

GLUG_LIB_API struct glug_sys *  glug_sys_create(void);
GLUG_LIB_API struct glug_sys *  glug_sys_free(struct glug_sys *);

GLUG_LIB_API uint32_t           glug_sys_cpus(struct glug_sys *);
GLUG_LIB_API uint32_t           glug_sys_active_cpus(struct glug_sys *);

GLUG_LIB_API uint64_t           glug_sys_mem(struct glug_sys *);

GLUG_EXTERN_END

#endif // GLUG_SYSTEM_H
