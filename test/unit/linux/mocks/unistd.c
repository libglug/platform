#include "unistd.h"

#include <stdio.h>

static int should_fail_open = 0;

void set_lscpu_output(const char *cpuline)
{
    FILE *lscpu = fopen("lscpu", "w");
    fputs(cpuline, lscpu);
    fclose(lscpu);
}

void set_lscpu_failure(int failures)
{
    should_fail_open = failures;
}

FILE *popen(const char *cmd, const char *mode)
{
    (void) cmd;
    (void) mode;

    if (!should_fail_open)
        return fopen("lscpu", "r");

    --should_fail_open;
    return NULL;
}

int pclose(FILE *stream)
{
    fclose(stream);
    return 0;
}
