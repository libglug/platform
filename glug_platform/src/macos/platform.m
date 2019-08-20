#import "../platform_platform.h"

#import <sys/utsname.h>
#import <stdio.h>
#import <Foundation/NSProcessInfo.h>

int os_version(struct glug_plat_version *version)
{
    if ([NSProcessInfo instancesRespondToSelector: @selector(operatingSystemVersion)] != YES) return 0;

    NSOperatingSystemVersion pi = [[NSProcessInfo processInfo] operatingSystemVersion];
    version->major = (uint32_t)pi.majorVersion;
    version->minor = (uint32_t)pi.minorVersion;
    version->patch = (uint32_t)pi.patchVersion;

    return 1;
}

int kernel_version(struct glug_plat_version *version)
{
    struct utsname utsname;
    uname(&utsname);

    sscanf(utsname.release, "%u.%u.%u", &version->major, &version->minor, &version->patch);

    return 1;
}
