#include "../platform_platform.h"

#include <Windows.h>

typedef void (WINAPI * RtlGetVersion_t) (OSVERSIONINFOEX *);

int os_version(struct glug_plat_version *version)
{
    HANDLE ntdll = LoadLibrary(TEXT("ntdll.dll"));
    RtlGetVersion_t RtlGetVersion = NULL;
    OSVERSIONINFOEX vi = {0};
    vi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

    if (ntdll && !(RtlGetVersion = (RtlGetVersion_t)GetProcAddress(ntdll, "RtlGetVersion")))
    {
        FreeLibrary(ntdll);
        return 0;
    }

    RtlGetVersion(&vi);
    FreeLibrary(ntdll);

    version->major = vi.dwMajorVersion;
    version->minor = vi.dwMinorVersion;
    version->patch = vi.wServicePackMajor;

    return 1;
}
