#include "system.h"

#include <inttypes.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>

static uint32_t parse_cpu_range(FILE *);

uint32_t cpus_linux(FILE *sys_cpu_pres)
{
    uint32_t ncpu = 0;

    if (!sys_cpu_pres) return ncpu;

    fseek(sys_cpu_pres, 0, SEEK_SET);
    ncpu = parse_cpu_range(sys_cpu_pres);

    return ncpu;
}

uint32_t active_cpus_linux(FILE *sys_cpu_onln)
{
    uint32_t ncpu = 0;

    if (!sys_cpu_onln) return ncpu;

    fseek(sys_cpu_onln, 0, SEEK_SET);
    ncpu = parse_cpu_range(sys_cpu_onln);

    return ncpu;
}

uint64_t physical_mem_linux(FILE *proc_meminfo)
{
    uint64_t bytes = 0;

    if (!proc_meminfo) return bytes;

    fseek(proc_meminfo, 0, SEEK_SET);
    while (!fscanf(proc_meminfo, "MemTotal: %"PRIu64"", &bytes))
        fscanf(proc_meminfo, "%*[^\n]\n"); // advance to next line

    return bytes * 1024;
}

static uint32_t parse_cpu_range(FILE *range)
{
    uint32_t min, max = 0, count = 0;
    int seperator = 0;

    while (fscanf(range, "%u", &min) > 0)
    {
        seperator = fgetc(range);
        if (seperator == ',')
        {
            // read a single value
            if(max == 0)
                ++count;
            // unset the max at the start of a range
            max = 0;
        }
        else if (seperator == '-')
        {
            // read the range's max and the diff to the count
            fscanf(range, "%u", &max);
            count += max - min + 1;
        }
        else
            ++count;
    }

    return count;
}
