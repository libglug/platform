#ifndef GLUG_SYSTEM_BUILDER_H
#define GLUG_SYSTEM_BUILDER_H

#include <stdint.h>
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_WIN

#include "win32/system_context.h"
typedef struct win32_context sys_context;

#elif GLUG_OS == GLUG_OS_MAC

#include "macos/system_context.h"
typedef struct macos_context sys_context;

#elif GLUG_OS == GLUG_OS_LIN

#include "linux/system_context.h"
#include "posix/system_context.h"
typedef struct
{
    struct linux_context lin;
    struct posix_context pos;
} sys_context;

#elif GLUG_OS == GLUG_OS_BSD

#include "bsd/system_context.h"
typedef struct bsd_context sys_context;

#elif GLUG_OS == GLUG_OS_UNK

#include "null/system_context.h"
typedef struct null_context sys_context;

#endif

struct glug_sys
{
    uint32_t (*cpu_count)(const sys_context *);
    uint32_t (*active_cpus)(const sys_context *);
    uint64_t (*physical_mem)(const sys_context *);
    sys_context context;
};

void build_system(struct glug_sys *);
void teardown_system(struct glug_sys *);

#endif // GLUG_SYSTEM_BUILDER_H
