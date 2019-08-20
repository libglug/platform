#include <iostream>

#include <glug/platform.h>

using namespace std;

int main(int, char **)
{
    glug_plat_version os_version;
    glug_plat_os_version(&os_version);

    cout << "OS version: " << os_version.major << os_version.minor<< os_version.patch << endl;

    return 0;
}
