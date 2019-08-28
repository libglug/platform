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

    cout << "CPUs: " << glug_sys_cpus(system) << endl;
    cout << "Active CPUs: " << glug_sys_active_cpus(system) << endl;
    cout << "System memory (in bytes): " << glug_sys_mem(system) << endl;

    return 0;
}
