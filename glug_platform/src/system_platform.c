#include "system_platform.h"

#include <glug/os.h>

#if defined(GLUG_OS_WIN)


#elif defined(GLUG_OS_MAC)

#elif  defined(GLUG_OS_LIN)

#include "linux/system.h"

bool (*(*get_cpu_count_fcn)(void))(uint32_t *) = get_cpu_count_linux;
bool (*(*get_active_cpus_fcn)(void))(uint32_t *) = get_active_cpus_linux;
bool (*(*get_physical_mem_fcn)(void))(uint64_t *) = get_physical_mem_linux;

#elif defined (GLUG_OS_BSD)

#include "bsd/system.h"

uint32_t (*(*get_cpu_count_fcn)(void))(void) = get_cpu_count_bsd;
uint32_t (*(*get_active_cpus_fcn)(void))(void) = get_active_cpus_bsd;
uint64_t (*(*get_physical_mem_fcn)(void))(void) = get_physical_mem_bsd;

#endif
