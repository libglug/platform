#include "system.h"

#include "../posix/system.h"
#include <stdio.h>
#include <unistd.h>

static bool cpu_count(uint32_t *ncpu)
{
    FILE *cpuinfo = popen("lscpu | grep ^CPU\\(s\\)", "r");
    *ncpu = 0;

    if (!cpuinfo) return false;

    fscanf(cpuinfo, "CPU(s): %u", ncpu);

    pclose(cpuinfo);
    return *ncpu > 0;
}

static bool active_cpus(uint32_t *ncpu)
{
    FILE *cpuinfo = popen("lscpu | grep ^On-line | grep -o \",\" | wc -l", "r");
    *ncpu = 0;

    if (!cpuinfo) return false;

    fscanf(cpuinfo, "%u", ncpu);

    pclose(cpuinfo);
    if (*ncpu > 0) *ncpu += 1;

    return *ncpu > 0;
}

static bool physical_memory(uint64_t *bytes)
{
    FILE *meminfo = popen("free -b | grep Mem:", "r");
    *bytes = 0;

    if (!meminfo) return false;

    fscanf(meminfo, "Mem: %lu", bytes);

    pclose(meminfo);
    return *bytes > 0;
}

bool (*get_cpu_count_linux(void))(uint32_t *)
{
    uint32_t cpus;
    bool (*get_cpus)(uint32_t *) = get_cpu_count_posix();
    if (get_cpus(&cpus))
        return get_cpus;

    return cpu_count;
}

bool (*get_active_cpus_linux(void))(uint32_t *)
{
    uint32_t cpus;
    bool (*get_active)(uint32_t *) = get_active_cpus_posix();
    if (get_active(&cpus))
        return get_active;

    return active_cpus;
}

bool (*get_physical_mem_linux(void))(uint64_t *)
{
    uint64_t mem;
    bool (*get_memory)(uint64_t *) = get_physical_mem_posix();
    if (get_memory(&mem))
        return get_memory;

    return physical_memory;
}
