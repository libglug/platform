#include "platform_builder.h"
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_WIN
#include "win32/platform.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

void build_platform(struct glug_plat *platform)
{
    HANDLE ntdll = LoadLibrary(TEXT("ntdll.dll"));
    HANDLE versiondll = LoadLibrary(TEXT("version.dll"));

    // os version
    if (ntdll)
    {
        FARPROC get_version = GetProcAddress(ntdll, TEXT("RtlGetVersion"));

        platform->ntdll = ntdll;
        platform->rtl_get_version = (RtlGetVersion_t)get_version;
    }

    // kernel version
    if (versiondll)
    {
        FARPROC get_ver_size = GetProcAddress(versiondll, TEXT("GetFileVersionInfoSizeA"));
        FARPROC get_ver_info = GetProcAddress(versiondll, TEXT("GetFileVersionInfoA"));
        FARPROC ver_query    = GetProcAddress(versiondll, TEXT("VerQueryValueA"));

        platform->versiondll = versiondll;
        platform->get_version_info_size = (GetFileVersionInfoSize_t)get_ver_size;
        platform->get_version_info      = (GetFileVersionInfo_t)get_ver_info;
        platform->version_query_value   = (VerQueryValue_t)ver_query;
    }
}

void teardown_platform(struct glug_plat *platform)
{
    if (platform)
    {
        if (platform->ntdll)
            FreeLibrary(platform->ntdll);

        if (platform->versiondll)
            FreeLibrary(platform->versiondll);
    }
}

enum glug_os os_plat(const struct glug_plat *platform)
{
    (void) platform;

    return os_win();
}

void os_version_plat(const struct glug_plat *platform, struct glug_plat_version *version)
{
    if (version && platform && platform->get_version_info_size)
        os_version_win(platform->rtl_get_version, version);
}

void kernel_version_plat(const struct glug_plat *platform, struct glug_plat_version *version)
{
    if (version && platform &&
        platform->get_version_info_size && platform->get_version_info && platform->version_query_value)
        kernel_version_win(platform->get_version_info_size, platform->get_version_info,
                           platform->version_query_value, version);
}

#endif // GLUG_OS == GLUG_OS_WIN
