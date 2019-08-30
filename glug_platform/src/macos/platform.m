#import "../platform_platform.h"

#import <sys/utsname.h>
#import <stdio.h>
#import <Foundation/NSProcessInfo.h>

static enum glug_os os(void)
{
    return glug_os_macos;
}

bool os_version(struct glug_plat_version *version)
{
    if ([NSProcessInfo instancesRespondToSelector: @selector(operatingSystemVersion)] != YES) return 0;

    NSOperatingSystemVersion pi = [[NSProcessInfo processInfo] operatingSystemVersion];
    version->major = (uint32_t)pi.majorVersion;
    version->minor = (uint32_t)pi.minorVersion;
    version->patch = (uint32_t)pi.patchVersion;

    return true;
}

bool kernel_version(struct glug_plat_version *version)
{
    struct utsname utsname;
    uname(&utsname);

    sscanf(utsname.release, "%u.%u.%u", &version->major, &version->minor, &version->patch);

    return true;
}

enum glug_os (*get_os_mac(void))(void)
{
    return os;
}

bool (*get_os_version_mac(void))(struct glug_plat_version *)
{
    return os_version;
}

bool (*get_kernel_version_mac(void))(struct glug_plat_version *)
{
    return kernel_version;
}
