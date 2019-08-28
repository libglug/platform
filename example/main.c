#include <stdio.h>

#include <glug/platform.h>

int main(int argc, char **argv)
{
    struct glug_plat_version os_vers, kern_vers;
    struct glug_plat *platform;
    struct glug_sys *system;
    (void) argc;
    (void) argv;

    platform = glug_plat_init();
    system = glug_sys_init();

    glug_plat_os_version(platform, &os_vers);
    glug_plat_kernel_version(platform, &kern_vers);

    printf("OS version: %d.%d.%d\n", os_vers.major, os_vers.minor, os_vers.patch);
    printf("Kernel version: %d.%d.%d\n", kern_vers.major, kern_vers.minor, kern_vers.patch);

    printf("CPUs: %d\n", glug_sys_cpus(system));
    printf("Active CPUs: %d\n", glug_sys_active_cpus(system));
    printf("System memory (in bytes): %lld\n", glug_sys_mem(system));

    return 0;
}
