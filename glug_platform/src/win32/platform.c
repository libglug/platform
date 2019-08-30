#include "../platform_platform.h"

#include <Windows.h>

typedef void (WINAPI * RtlGetVersion_t) (OSVERSIONINFOEX *);

static enum glug_os os(void)
{
    return glug_os_windows;
}

static bool os_version(struct glug_plat_version *version)
{
    HANDLE ntdll = LoadLibrary(TEXT("ntdll.dll"));
    RtlGetVersion_t RtlGetVersion = NULL;
    OSVERSIONINFOEX vi = {0};
    vi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

    if (ntdll && !(RtlGetVersion = (RtlGetVersion_t)GetProcAddress(ntdll, "RtlGetVersion")))
    {
        FreeLibrary(ntdll);
        return false;
    }

    RtlGetVersion(&vi);
    FreeLibrary(ntdll);

    version->major = vi.dwMajorVersion;
    version->minor = vi.dwMinorVersion;
    version->patch = vi.wServicePackMajor;

    return true;
}

static bool kernel_version(struct glug_plat_version *version)
{
    DWORD len = GetFileVersionInfoSize(TEXT("Kernel32.dll"), NULL);
    void *fvi = malloc(len);
    PUINT bytes = 0;
    LPVOID vqv;

    GetFileVersionInfo(TEXT("Kernel32.dll"), 0, len, fvi);
    if (!VerQueryValue(fvi, "\\", &vqv, bytes))
    {
        free(fvi);
        return false;
    }

    VS_FIXEDFILEINFO *file_info = (VS_FIXEDFILEINFO *)vqv;
    version->major = HIWORD(file_info->dwFileVersionMS);
    version->minor = LOWORD(file_info->dwFileVersionMS);
    version->patch = HIWORD(file_info->dwFileVersionLS);
    free(fvi);

    return true;
}

enum glug_os (*get_os_win(void))(void)
{
    return os;
}

int (*get_os_version_win(void))(struct glug_plat_version *)
{
    return os_version;
}

int (*get_kernel_version_win(void))(struct glug_plat_version *)
{
    return kernel_version;
}
