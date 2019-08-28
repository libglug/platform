#include <iostream>

#include <glug/platform.h>

using namespace std;

int main(int, char **)
{
    glug_plat_version os_vers, kern_vers;
    glug_plat *platform = glug_plat_init();
    glug_sys *system = glug_sys_init();

    glug_plat_os_version(platform, &os_vers);
    glug_plat_kernel_version(platform, &kern_vers);

    cout << "OS version: " << os_vers.major << "." <<
                              os_vers.minor << "." <<
                              os_vers.patch << endl;
    cout << "Kernel version: " << kern_vers.major << "." <<
                                  kern_vers.minor << "." <<
                                  kern_vers.patch << endl;

    uint32_t ncpu, nactive;
    uint64_t memory;
    glug_sys_cpus(system, &ncpu);
    glug_sys_active_cpus(system, &nactive);
    glug_sys_mem(system, &memory);

    cout << "CPUs: " << ncpu << endl <<
            "Active CPUs: " << nactive << endl <<
            "System memory (in bytes): " << memory << endl;

    return 0;
}
