#include "system.h"

#include <stdio.h>
#include <unistd.h>

glug_bool cpu_count_linux(uint32_t *ncpu)
{
    FILE *cpuinfo = popen("lscpu | grep ^CPU\\(s\\)", "r");
    *ncpu = 0;

    if (!cpuinfo) return false;

    fscanf(cpuinfo, "CPU(s): %u", ncpu);

    pclose(cpuinfo);
    return *ncpu > 0;
}

glug_bool active_cpus_linux(uint32_t *ncpu)
{
    FILE *cpuinfo = popen("lscpu | grep ^On-line | grep -o \",\" | wc -l", "r");
    *ncpu = 0;

    if (!cpuinfo) return false;

    fscanf(cpuinfo, "%u", ncpu);

    pclose(cpuinfo);
    if (*ncpu > 0) *ncpu += 1;

    return *ncpu > 0;
}

glug_bool physical_mem_linux(uint64_t *bytes)
{
    FILE *meminfo = popen("free -b | grep Mem:", "r");
    *bytes = 0;

    if (!meminfo) return false;

    fscanf(meminfo, "Mem: %lu", bytes);

    pclose(meminfo);
    return *bytes > 0;
}
