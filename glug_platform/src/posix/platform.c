#include "platform.h"
#include "platform_context.h"

#include <sys/utsname.h>
#include <stdio.h>
#include <string.h>

glug_bool os_version_posix(struct glug_plat_version *version, const struct posix_context *context)
{
    // lsb, not posix, but who's keeping track?
    FILE *lsb_release = context->lsb_release;
    char tmp[20];
    int read = 0;
    unsigned int ntmp = 123;

    fseek(lsb_release, 0, SEEK_SET);

    while((read = fscanf(lsb_release, " %20[^=]", tmp)))
    {
        if (!strcmp(tmp, "DISTRIB_RELEASE"))
        {
            fscanf(lsb_release, "=%u.%u.%u.%u", &version->major, &version->minor, &version->patch, &ntmp);
            return true;
        }
        // advance to next line
        fscanf(lsb_release, "%*[^\n]");
    }

    return false;
}

glug_bool kernel_version_posix(struct glug_plat_version *version, const struct posix_context *context)
{
    struct utsname utsname;
    int res = context->uname(&utsname);

    if (res == -1)
        return false;

    sscanf(utsname.release, "%u.%u.%u", &version->major, &version->minor, &version->patch);

    return true;
}
