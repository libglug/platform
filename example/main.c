#include <stdio.h>

#include <glug/platform.h>

int main(int argc, char **argv)
{
    struct glug_plat_version os_version;
    (void) argc;
    (void) argv;

    glug_plat_os_version(&os_version);

    printf("OS version: %d.%d.%d\n", os_version.major, os_version.minor, os_version.patch);

    return 0;
}
