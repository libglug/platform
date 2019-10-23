#include "platform_builder.h"
#include "null/platform.h"

#include <glug/os.h>

typedef glug_bool (*unused_context)(struct glug_plat_version *, const plat_context *);

#if defined(GLUG_OS_WIN)

#include "win32/platform.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

static enum glug_os get_os_win(const plat_context *context)
{
    return os_win(&context->win);
}

static glug_bool get_os_version_win(struct glug_plat_version *version, const plat_context *context)
{
    return os_version_win(version, &context->win);
}

static glug_bool get_kernel_version_win(struct glug_plat_version *version, const plat_context *context)
{
    return kernel_version_win(version, &context->win);
}

void build_platform(struct glug_plat *platform)
{
    HANDLE ntdll = LoadLibrary(TEXT("ntdll.dll"));
    HANDLE versiondll = LoadLibrary(TEXT("version.dll"));
    plat_context *context = &platform->plat_context;

    platform->os = get_os_win;
    platform->os_version = (unused_context)os_version_null;
    platform->kernel_version = (unused_context)os_version_null;

    if (ntdll)
    {
        RtlGetVersion_t get_version = (RtlGetVersion_t)GetProcAddress(ntdll, TEXT("RtlGetVersion"));
        if (get_version)
        {
            context->win.rtl_get_version = get_version;
            platform->os_version = get_os_version_win;
        }

        context->ntdll = ntdll;
    }

    if (versiondll)
    {
        FARPROC get_ver_size = GetProcAddress(versiondll, TEXT("GetFileVersionInfoSizeA"));
        FARPROC get_ver_info = GetProcAddress(versiondll, TEXT("GetFileVersionInfoA"));
        FARPROC ver_query    = GetProcAddress(versiondll, TEXT("VerQueryValueA"));
        if (get_ver_size && get_ver_info && ver_query)
        {
            context->win.get_version_info_size = (GetFileVersionInfoSize_t )get_ver_size;
            context->win.get_version_info      = (GetFileVersionInfo_t)get_ver_info;
            context->win.version_query_value   = (VerQueryValue_t)ver_query;
            platform->kernel_version           = get_kernel_version_win;
        }

        context->versiondll = versiondll;
    }
}

void teardown_platform(struct glug_plat *platform)
{
    if (platform)
    {
        if (platform->plat_context.ntdll)
            FreeLibrary(platform->plat_context.ntdll);

        if (platform->plat_context.versiondll)
            FreeLibrary(platform->plat_context.versiondll);
    }
}

#elif defined(GLUG_OS_MAC)

#include "macos/platform.h"

void build_platform(struct glug_plat *platform)
{
    platform->os = os_mac;
    platform->os_version = responds_to_osversion() ? os_version_mac : os_version_fallback_mac;
    platform->kernel_version = kernel_version_mac;
}

void teardown_platform(struct glug_plat *platform)
{
    (void) platform;
}

#elif defined(GLUG_OS_LIN)

#include "linux/platform.h"
#include "posix/platform.h"

#include <dlfcn.h>

static enum glug_os get_os_linux(const plat_context *context)
{
    return os_linux(&context->lin);
}

static glug_bool get_os_version_linux(struct glug_plat_version *version, const plat_context *context)
{
    return os_version_linux(version, &context->lin);
}

static glug_bool get_os_version_posix(struct glug_plat_version *version, const plat_context *context)
{
    return os_version_posix(version, &context->pos);
}

static glug_bool get_kernel_version_linux(struct glug_plat_version *version, const plat_context *context)
{
    return kernel_version_linux(version, &context->lin);
}

static glug_bool get_kernel_version_posix(struct glug_plat_version *version, const plat_context *context)
{
    return kernel_version_posix(version, &context->pos);
}

#include <string.h>

void build_platform(struct glug_plat *platform)
{
    FILE *proc_version = NULL, *lsb_release = NULL;
    plat_context *context = &platform->plat_context;
    void *libc = dlopen(0, RTLD_NOW);

    platform->os = get_os_linux;
    platform->os_version = (unused_context)os_version_null;
    platform->kernel_version = (unused_context)os_version_null;

    if (libc)
    {
        int (*uname)(struct utsname *) = (int (*)(struct utsname *))dlsym(libc, "uname");
        if (uname)
        {
            context->pos.uname = uname;
            platform->kernel_version = get_kernel_version_posix;
        }
    }
    else if ((proc_version = fopen("/proc/version", "r")))
    {
        context->lin.proc_version = proc_version;
        platform->kernel_version = get_kernel_version_linux;
    }

    if ((lsb_release = fopen("/etc/lsb-release", "r")))
    {
        context->pos.lsb_release = lsb_release;
        platform->os_version = get_os_version_posix;
    }

    dlclose(libc);
}

void teardown_platform(struct glug_plat *platform)
{
    if (platform->plat_context.lin.proc_version)
        fclose(platform->plat_context.lin.proc_version);

    if (platform->plat_context.pos.lsb_release)
        fclose(platform->plat_context.pos.lsb_release);
}

#elif defined(GLUG_OS_BSD)

#include "bsd/platform.h"

void build_platform(struct glug_plat *platform)
{
    platform->os = os_bsd;
    platform->os_version = os_version_bsd;
    platform->kernel_version = kernel_version_bsd;
}

#else // null

void build_platform(struct glug_plat *platform)
{
    platform->os = os_null;
    platform->os_version = os_version_null;
    platform->kernel_version = kernel_version_null;
}

#endif
