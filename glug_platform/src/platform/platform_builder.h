#ifndef GLUG_PLATFORM_PLATFORM_H
#define GLUG_PLATFORM_PLATFORM_H

#include <glug/platform/os.h>
#include <glug/platform/version_t.h>
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_WIN

#include "win32/platform_context.h"
typedef struct {
    HANDLE ntdll;
    HANDLE versiondll;
    struct win32_context win;
} plat_context;

#elif GLUG_OS == GLUG_OS_MAC

#include "macos/platform_context.h"
typedef struct macos_context plat_context;

#elif GLUG_OS == GLUG_OS_LIN

#include "linux/platform_context.h"
#include "posix/platform_context.h"
typedef struct
{
    struct linux_context lin;
    struct posix_context pos;
} plat_context;

#elif GLUG_OS == GLUG_OS_BSD

#include "bsd/platform_context.h"
typedef struct bsd_context plat_context;

#elif GLUG_OS == GLUG_OS_UNK

#include "null/platform_context.h"
typedef struct null_context plat_context;

#endif

struct glug_plat
{
    enum glug_os (*os)(const plat_context *);
    void         (*os_version)(struct glug_plat_version *, const plat_context *);
    void         (*kernel_version)(struct glug_plat_version *, const plat_context *);
    plat_context plat_context;
};

void build_platform(struct glug_plat *);
void teardown_platform(struct glug_plat *);

#endif // GLUG_PLATFORM_PLATFORM_H
