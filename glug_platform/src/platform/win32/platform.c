#include "platform.h"

#include <Windows.h>
#include <stdlib.h>

enum glug_os os_win(void)
{
    return glug_os_windows;
}

void os_version_win(const RtlGetVersion_t rtl_get_version, struct glug_plat_version *version)
{
    OSVERSIONINFOEX vi = {0};
    vi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

    rtl_get_version(&vi);

    version->major = vi.dwMajorVersion;
    version->minor = vi.dwMinorVersion;
    version->patch = vi.wServicePackMajor;
}

void kernel_version_win(GetFileVersionInfoSize_t get_version_info_size, GetFileVersionInfo_t get_version_info,
                        VerQueryValue_t version_query_value, struct glug_plat_version *version)
{
    DWORD len = get_version_info_size("Kernel32.dll", NULL);
    LPVOID fvi = malloc(len), vqv;
    UINT bytes = 0;

    get_version_info("Kernel32.dll", 0, len, fvi);
    if (!version_query_value(fvi, "\\", &vqv, &bytes))
    {
        free(fvi);
        return;
    }

    VS_FIXEDFILEINFO *file_info = (VS_FIXEDFILEINFO *)vqv;
    version->major = HIWORD(file_info->dwFileVersionMS);
    version->minor = LOWORD(file_info->dwFileVersionMS);
    version->patch = HIWORD(file_info->dwFileVersionLS);
    free(fvi);
}
