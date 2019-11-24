#ifndef GLUG_PLATFORM_WIN32_H
#define GLUG_PLATFORM_WIN32_H

#include <glug/platform/os.h>
#include <glug/platform/version_t.h>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

typedef void (*RtlGetVersion_t)(OSVERSIONINFOEX *);
typedef DWORD (*GetFileVersionInfoSize_t)(LPCSTR, LPDWORD);
typedef DWORD (*GetFileVersionInfo_t)(LPCSTR, DWORD, DWORD, LPVOID);
typedef BOOL (*VerQueryValue_t)(LPCVOID, LPCSTR, LPVOID *, PUINT);

enum glug_os    os_win(void);
void            os_version_win(const RtlGetVersion_t, struct glug_plat_version *);
void            kernel_version_win(GetFileVersionInfoSize_t, GetFileVersionInfo_t,
                                   VerQueryValue_t, struct glug_plat_version *);

#endif // GLUG_PLATFORM_WIN32_H
