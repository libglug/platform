#ifndef GLUG_PLATFORM_PLATFORM_H
#define GLUG_PLATFORM_PLATFORM_H

#include <glug/platform/os.h>
#include <glug/platform/version_t.h>
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_WIN

#include "win32/platform.h"

struct glug_plat
{
    HANDLE                   ntdll;
    HANDLE                   versiondll;
    RtlGetVersion_t          rtl_get_version;
    GetFileVersionInfoSize_t get_version_info_size;
    GetFileVersionInfo_t     get_version_info;
    VerQueryValue_t          version_query_value;
};

#elif GLUG_OS == GLUG_OS_MAC

#include "macos/platform.h"
struct glug_plat
{
    glug_bool use_fallback;
    FILE     *product_version;
};

#elif GLUG_OS == GLUG_OS_LIN

#include "linux/platform.h"
struct glug_plat
{
    void    *libc;
    FILE    *lsb_release;
    uname_t  uname;
    FILE    *proc_version;
};

#elif GLUG_OS == GLUG_OS_BSD

#include "bsd/platform.h"
struct glug_plat
{
    void     *libc;
    sysctl_t  sysctl;
};

#elif GLUG_OS == GLUG_OS_UNK

struct glug_plat
{
    void *_unused;
};

#endif

GLUG_LIB_LOCAL void         build_platform(struct glug_plat *);
GLUG_LIB_LOCAL void         teardown_platform(struct glug_plat *);

GLUG_LIB_LOCAL enum glug_os os_plat(const struct glug_plat *);
GLUG_LIB_LOCAL void         os_version_plat(const struct glug_plat *, struct glug_plat_version *);
GLUG_LIB_LOCAL void         kernel_version_plat(const struct glug_plat *, struct glug_plat_version *);

#endif // GLUG_PLATFORM_PLATFORM_H
