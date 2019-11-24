#include "system_builder.h"
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_MAC
#include "macos/system.h"

void build_system(struct glug_sys *system)
{
    (void) system;
}

void teardown_system(struct glug_sys *system)
{
    (void) system;
}

uint32_t cpus_plat(const struct glug_sys *system)
{
    (void) system;

    return cpus_mac();
}

uint32_t active_cpus_plat(const struct glug_sys *system)
{
    (void) system;

    return active_cpus_mac();
}

uint64_t physical_mem_plat(const struct glug_sys *system)
{
    (void) system;

    return physical_mem_mac();
}

#endif // GLUG_OS == GLUG_OS_MAC
