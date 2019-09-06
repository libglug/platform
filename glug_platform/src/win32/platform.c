#include "platform.h"
#include <Windows.h>

typedef void (WINAPI * RtlGetVersion_t)(OSVERSIONINFOEX *);
typedef DWORD (*GetFileVersionInfoSize_t)(LPCSTR, LPDWORD);
typedef DWORD (*GetFileVersionInfo_t)(LPCSTR, DWORD, DWORD, LPVOID);
typedef BOOL (*VerQueryValue_t)(LPCVOID, LPCSTR, LPVOID *, PUINT);

enum glug_os os_win(void)
{
    return glug_os_windows;
}

glug_bool os_version_win(struct glug_plat_version *version)
{
    HANDLE ntdll = LoadLibrary(TEXT("ntdll.dll"));
    RtlGetVersion_t RtlGetVersion = NULL;
    OSVERSIONINFOEX vi = {0};
    vi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

    if (!ntdll || !(RtlGetVersion = (RtlGetVersion_t)GetProcAddress(ntdll, TEXT("RtlGetVersion"))))
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

glug_bool kernel_version_win(struct glug_plat_version *version)
{
    HANDLE versiondll = LoadLibrary(TEXT("version.dll"));
    GetFileVersionInfoSize_t GetFileVersionInfoSize = NULL;
    GetFileVersionInfo_t GetFileVersionInfo = NULL;
    VerQueryValue_t VerQueryValue = NULL;
    DWORD len = 0;
    void *fvi = NULL;
    PUINT bytes = 0;
    LPVOID vqv;

    if (!versiondll ||
        !(GetFileVersionInfoSize = (GetFileVersionInfoSize_t)GetProcAddress(versiondll, TEXT("GetFileVersionInfoSizeA"))) ||
        !(GetFileVersionInfo = (GetFileVersionInfo_t)GetProcAddress(versiondll, TEXT("GetFileVersionInfoA"))) ||
        !(VerQueryValue = (VerQueryValue_t)GetProcAddress(versiondll, TEXT("VerQueryValueA"))))
    {
        FreeLibrary(versiondll);
        return false;
    }

    len = GetFileVersionInfoSize("Kernel32.dll", NULL);
    fvi = malloc(len);

    GetFileVersionInfo("Kernel32.dll", 0, len, fvi);
    if (!VerQueryValue(fvi, "\\", &vqv, bytes))
    {
        free(fvi);
        return false;
    }
    FreeLibrary(versiondll);

    VS_FIXEDFILEINFO *file_info = (VS_FIXEDFILEINFO *)vqv;
    version->major = HIWORD(file_info->dwFileVersionMS);
    version->minor = LOWORD(file_info->dwFileVersionMS);
    version->patch = HIWORD(file_info->dwFileVersionLS);
    free(fvi);

    return true;
}
