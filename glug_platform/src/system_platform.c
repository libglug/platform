#include "system_platform.h"

#include <glug/os.h>

#if defined(GLUG_OS_WIN)

#include "win32/system.h"

bool (*(*get_cpu_count_fcn)(void))(uint32_t *) = get_cpu_count_win;
bool (*(*get_active_cpus_fcn)(void))(uint32_t *) = get_active_cpus_win;
bool (*(*get_physical_mem_fcn)(void))(uint64_t *) = get_physical_mem_win;

#elif defined(GLUG_OS_MAC)

#include "macos/system.h"

bool (*(*get_cpu_count_fcn)(void))(uint32_t *) = get_cpu_count_mac;
bool (*(*get_active_cpus_fcn)(void))(uint32_t *) = get_active_cpus_mac;
bool (*(*get_physical_mem_fcn)(void))(uint64_t *) = get_physical_mem_mac;

#elif  defined(GLUG_OS_LIN)

#include "linux/system.h"

bool (*(*get_cpu_count_fcn)(void))(uint32_t *) = get_cpu_count_linux;
bool (*(*get_active_cpus_fcn)(void))(uint32_t *) = get_active_cpus_linux;
bool (*(*get_physical_mem_fcn)(void))(uint64_t *) = get_physical_mem_linux;

#elif defined (GLUG_OS_BSD)

#include "bsd/system.h"

bool (*(*get_cpu_count_fcn)(void))(uint32_t *) = get_cpu_count_bsd;
bool (*(*get_active_cpus_fcn)(void))(uint32_t *) = get_active_cpus_bsd;
bool (*(*get_physical_mem_fcn)(void))(uint64_t *) = get_physical_mem_bsd;

#endif
