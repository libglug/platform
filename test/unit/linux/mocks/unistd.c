#include "unistd.h"

#include <stdio.h>

static int should_fail_open = 0;

void set_popen_output(const char *cpuline)
{
    FILE *lscpu = fopen("lscpu", "w");
    fprintf(lscpu, "%s", cpuline);
    fclose(lscpu);
}

void set_popen_failure_count(int failures)
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
