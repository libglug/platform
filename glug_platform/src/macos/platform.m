#import "platform.h"
#import "platform_context.h"

#import <sys/utsname.h>
#import <stdio.h>
#import <Foundation/NSProcessInfo.h>

enum glug_os os_mac(const struct macos_context *context)
{
    (void) context;
    return glug_os_macos;
}

glug_bool os_version_mac(struct glug_plat_version *version, const struct macos_context *context)
{
    (void) context;
    NSOperatingSystemVersion os_vers = [[NSProcessInfo processInfo] operatingSystemVersion];
    version->major = (uint32_t)os_vers.majorVersion;
    version->minor = (uint32_t)os_vers.minorVersion;
    version->patch = (uint32_t)os_vers.patchVersion;

    return true;
}

glug_bool kernel_version_mac(struct glug_plat_version *version, const struct macos_context *context)
{
    (void) context;
    struct utsname utsname;
    uname(&utsname);

    sscanf(utsname.release, "%u.%u.%u", &version->major, &version->minor, &version->patch);

    return true;
}

glug_bool responds_to_osversion(void)
{
    return [NSProcessInfo instancesRespondToSelector: @selector(operatingSystemVersion)] == YES;
}

glug_bool os_version_fallback_mac(struct glug_plat_version *version, const struct macos_context *context)
{
    FILE *sw_vers = popen("sw_vers -productVersion", "r");

    if (!sw_vers) return false;

    fscanf(sw_vers, "%u.%u.%u", &version->major, &version->minor, &version->patch);
    pclose(sw_vers);

    return true;
}
