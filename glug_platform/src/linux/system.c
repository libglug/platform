#include "system.h"

#include <inttypes.h>
#include <stdio.h>
#include <unistd.h>

uint32_t cpu_count_linux()
{
    FILE *cpuinfo = popen("lscpu | grep ^CPU\\(s\\)", "r");
    uint32_t ncpu = 0;

    if (!cpuinfo) return ncpu;

    fscanf(cpuinfo, "CPU(s): %u", &ncpu);

    pclose(cpuinfo);
    return ncpu;
}

uint32_t active_cpus_linux()
{
    FILE *cpuinfo = popen("lscpu | grep ^On-line | grep -o \",\" | wc -l", "r");
    uint32_t ncpu = 0;

    if (!cpuinfo) return ncpu;

    fscanf(cpuinfo, "%u", &ncpu);

    pclose(cpuinfo);
    if (ncpu > 0) ncpu += 1;

    return ncpu;
}

uint64_t physical_mem_linux()
{
    FILE *meminfo = popen("free -b | grep Mem:", "r");
    uint64_t bytes = 0;

    if (!meminfo) return 0;

    fscanf(meminfo, "Mem: %"PRIu64"", &bytes);

    pclose(meminfo);
    return bytes;
}
