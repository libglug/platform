#include "platform.h"
#include "platform_context.h"

#include <Windows.h>
#include <stdlib.h>

enum glug_os os_win(const struct win32_context *context)
{
    (void) context;

    return glug_os_windows;
}

void os_version_win(struct glug_plat_version *version, const struct win32_context *context)
{
    OSVERSIONINFOEX vi = {0};
    vi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

    context->rtl_get_version(&vi);

    version->major = vi.dwMajorVersion;
    version->minor = vi.dwMinorVersion;
    version->patch = vi.wServicePackMajor;
}

void kernel_version_win(struct glug_plat_version *version, const struct win32_context *context)
{
    DWORD len = 0;
    void *fvi = NULL;
    PUINT bytes = 0;
    LPVOID vqv;

    len = context->get_version_info_size("Kernel32.dll", NULL);
    fvi = malloc(len);

    context->get_version_info("Kernel32.dll", 0, len, fvi);
    if (!context->version_query_value(fvi, "\\", &vqv, bytes))
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
