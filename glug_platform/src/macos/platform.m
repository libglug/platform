#import "platform.h"

#import <sys/utsname.h>
#import <stdio.h>
#import <Foundation/NSProcessInfo.h>

enum glug_os os_mac(void)
{
    return glug_os_macos;
}

glug_bool os_version_mac(struct glug_plat_version *version)
{
    if ([NSProcessInfo instancesRespondToSelector: @selector(operatingSystemVersion)] != YES) return 0;

    NSOperatingSystemVersion pi = [[NSProcessInfo processInfo] operatingSystemVersion];
    version->major = (uint32_t)pi.majorVersion;
    version->minor = (uint32_t)pi.minorVersion;
    version->patch = (uint32_t)pi.patchVersion;

    return true;
}

glug_bool kernel_version_mac(struct glug_plat_version *version)
{
    struct utsname utsname;
    uname(&utsname);

    sscanf(utsname.release, "%u.%u.%u", &version->major, &version->minor, &version->patch);

    return true;
}
