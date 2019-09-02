#include "system.h"

glug_bool cpu_count_null(uint32_t *ncpu)
{
    (void) ncpu;
    return false;
}

glug_bool active_cpus_null(uint32_t *ncpu)
{
    (void) ncpu;
    return false;
}

glug_bool physical_mem_null(uint64_t *bytes)
{
    (void) bytes;
    return false;
}
