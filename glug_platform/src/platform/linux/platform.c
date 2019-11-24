#include "platform.h"

#include <stdio.h>
#include <string.h>
#include <sys/utsname.h>

enum glug_os os_linux(void)
{
    return glug_os_linux;
}

void os_version_linux(struct glug_plat_version *version)
{
    (void) version;
}

void os_version_lsb(FILE *lsb_release, struct glug_plat_version *version)
{
    char tmp[20];
    int read = 0;

    fseek(lsb_release, 0, SEEK_SET);

    while((read = fscanf(lsb_release, " %20[^=]", tmp)))
    {
        if (!strcmp(tmp, "DISTRIB_RELEASE"))
        {
            fscanf(lsb_release, "=%u.%u.%u.%*u", &version->major, &version->minor, &version->patch);
            return;
        }
        // advance to next line
        fscanf(lsb_release, "%*[^\n]");
    }
}

void kernel_version_linux(FILE *proc_version, struct glug_plat_version *version)
{
    fseek(proc_version, 0, SEEK_SET);
    fscanf(proc_version, "%*[^0-9] %u.%u.%u", &version->major, &version->minor, &version->patch);
}

void kernel_version_uname(const uname_t uname, struct glug_plat_version *version)
{
    struct utsname utsname;

    if (uname(&utsname) == -1)
        return;

    sscanf(utsname.release, "%u.%u.%u", &version->major, &version->minor, &version->patch);
}
