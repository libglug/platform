#import "platform.h"

#import <stdio.h>
#import <sys/utsname.h>
#import <Foundation/NSProcessInfo.h>

enum glug_os os_mac(void)
{
    return glug_os_macos;
}

void os_version_mac(struct glug_plat_version *version)
{
    NSOperatingSystemVersion os_vers = [[NSProcessInfo processInfo] operatingSystemVersion];
    version->major = (uint32_t)os_vers.majorVersion;
    version->minor = (uint32_t)os_vers.minorVersion;
    version->patch = (uint32_t)os_vers.patchVersion;
}

void kernel_version_mac(struct glug_plat_version *version)
{
    struct utsname utsname;
    uname(&utsname);

    sscanf(utsname.release, "%u.%u.%u", &version->major, &version->minor, &version->patch);
}

glug_bool responds_to_osversion(void)
{
    return [NSProcessInfo instancesRespondToSelector: @selector(operatingSystemVersion)] == YES;
}

void os_version_fallback_mac(FILE *product_version, struct glug_plat_version *version)
{
    if (!product_version) return;

    fscanf(product_version, "%u.%u.%u", &version->major, &version->minor, &version->patch);
    pclose(product_version);
}
