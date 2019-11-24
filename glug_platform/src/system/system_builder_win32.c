#include "system_builder.h"
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_WIN
#include "win32/system.h"

void build_system(struct glug_sys *system)
{
    HANDLE ntdll = LoadLibrary(TEXT("Kernel32.dll"));

    if (ntdll)
    {
        FARPROC get_sysinfo = GetProcAddress(ntdll, TEXT("GetNativeSystemInfo"));
        FARPROC get_memory  = GetProcAddress(ntdll, TEXT("GetPhysicallyInstalledSystemMemory"));

        system->ntdll = ntdll;
        system->get_native_sysinfo = (GetNSInfo_t)get_sysinfo;
        system->get_phys_memory    = (GetPISMemory_t)get_memory;
    }
}

void teardown_system(struct glug_sys *system)
{
    if (system)
    {
        if (system->ntdll)
            FreeLibrary(system->ntdll);
    }
}

uint32_t cpus_plat(const struct glug_sys *system)
{
    if (system && system->get_native_sysinfo)
        return cpus_win(system->get_native_sysinfo);

    return 0;
}

uint32_t active_cpus_plat(const struct glug_sys *system)
{
    if (system && system->get_native_sysinfo)
        return active_cpus_win(system->get_native_sysinfo);

    return 0;
}

uint64_t physical_mem_plat(const struct glug_sys *system)
{
    if (system && system->get_phys_memory)
        return physical_mem_win(system->get_phys_memory);

    return 0;
}

#endif // GLUG_OS == GLUG_OS_WIN
