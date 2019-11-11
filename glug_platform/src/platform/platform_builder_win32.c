#include <glug/os.h>

#if GLUG_OS == GLUG_OS_WIN

#include "platform_builder.h"
#include "win32/platform.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

static enum glug_os get_os_win(const plat_context *context)
{
    return os_win(&context->win);
}

static void get_os_version_win(struct glug_plat_version *version, const plat_context *context)
{
    os_version_win(version, &context->win);
}

static void get_kernel_version_win(struct glug_plat_version *version, const plat_context *context)
{
    kernel_version_win(version, &context->win);
}

void build_platform(struct glug_plat *platform)
{
    HANDLE ntdll = LoadLibrary(TEXT("ntdll.dll"));
    HANDLE versiondll = LoadLibrary(TEXT("version.dll"));
    plat_context *context = &platform->plat_context;

    platform->os = get_os_win;

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

#endif // GLUG_OS == GLUG_OS_WIN
