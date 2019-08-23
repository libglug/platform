#include <stdio.h>

#include <glug/platform.h>

int main(int argc, char **argv)
{
    struct glug_plat_version os_vers, kern_vers;
    (void) argc;
    (void) argv;

    glug_plat_os_version(&os_vers);
    glug_plat_kernel_version(&kern_vers);

    printf("OS version: %d.%d.%d\n", os_vers.major, os_vers.minor, os_vers.patch);
    printf("Kernel version: %d.%d.%d\n", kern_vers.major, kern_vers.minor, kern_vers.patch);

    printf("CPUs: %d\n", glug_sys_cpus());
    printf("Active CPUs: %d\n", glug_sys_active_cpus());
    printf("System memory (in bytes): %lld\n", glug_sys_mem());

    return 0;
}
