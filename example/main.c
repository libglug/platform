#include <glug/platform.h>

#include <stdio.h>
#include <inttypes.h>

int main(int argc, char **argv)
{
    struct glug_plat_version os_vers, kern_vers;
    struct glug_plat *platform;
    struct glug_sys *system;
    uint32_t ncpu, nactive;
    uint64_t memory;
    (void) argc;
    (void) argv;

    platform = glug_plat_create();
    system   = glug_sys_create();

    glug_plat_os_version(platform, &os_vers);
    glug_plat_kernel_version(platform, &kern_vers);

    printf("OS version: %d.%d.%d\n", os_vers.major, os_vers.minor, os_vers.patch);
    printf("Kernel version: %d.%d.%d\n", kern_vers.major, kern_vers.minor, kern_vers.patch);

//    ncpu = glug_sys_cpus(system);
//    nactive = glug_sys_active_cpus(system);
//    memory = glug_sys_mem(system);

//    printf("CPUs: %u\n", ncpu);
//    printf("Active CPUs: %u\n", nactive);
//    printf("System memory (in bytes): %"PRIu64"\n", memory);

    platform = glug_plat_free(platform);
    system   = glug_sys_free(system);

    return 0;
}
