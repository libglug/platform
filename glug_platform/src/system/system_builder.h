#ifndef GLUG_SYSTEM_BUILDER_H
#define GLUG_SYSTEM_BUILDER_H

#include <stdint.h>

struct win32_context
{
    void (*a)(void);
    void (*b)(void);
};

struct macos_context
{
    void (*c)(int);
    void (*d)(int);
};

union sys_context
{
    struct win32_context win32_context;
    struct macos_context macos_context;
};

struct glug_sys
{
    uint32_t (*cpu_count)(void);
    uint32_t (*active_cpus)(void);
    uint64_t (*physical_mem)(void);
    union sys_context context;
    void (*free_context)(union sys_context *);
};

void build_system(struct glug_sys *);

#endif // GLUG_SYSTEM_BUILDER_H
