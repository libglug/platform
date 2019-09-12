#ifndef WIN32_PLATFORM_CONTEXT_H
#define WIN32_PLATFORM_CONTEXT_H

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

typedef void (WINAPI * RtlGetVersion_t)(OSVERSIONINFOEX *);
typedef DWORD (*GetFileVersionInfoSize_t)(LPCSTR, LPDWORD);
typedef DWORD (*GetFileVersionInfo_t)(LPCSTR, DWORD, DWORD, LPVOID);
typedef BOOL (*VerQueryValue_t)(LPCVOID, LPCSTR, LPVOID *, PUINT);

struct win32_context
{
    HANDLE ntdll;
    HANDLE versiondll;
    RtlGetVersion_t rtl_get_version;
    GetFileVersionInfoSize_t get_version_info_size;
    GetFileVersionInfo_t get_version_info;
    VerQueryValue_t version_query_value;
};

#endif // WIN32_PLATFORM_CONTEXT_H
