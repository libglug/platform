#include <iostream>

#include <glug/platform.h>

using namespace std;

int main(int, char **)
{
    glug_plat_version os_vers, kern_vers;
    glug_plat_os_version(&os_vers);
    glug_plat_kernel_version(&kern_vers);

    cout << "OS version: " << os_vers.major << "." <<
                              os_vers.minor << "." <<
                              os_vers.patch << endl;
    cout << "Kernel version: " << kern_vers.major << "." <<
                                  kern_vers.minor << "." <<
                                  kern_vers.patch << endl;

    return 0;
}
