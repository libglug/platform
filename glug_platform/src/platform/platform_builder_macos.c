#include "platform_builder.h"
#include <glug/os.h>

#if GLUG_OS == GLUG_OS_MAC
#include "macos/platform.h"

void build_platform(struct glug_plat *platform)
{
    platform->use_fallback = responds_to_osversion();
    platform->product_version = popen("sw_vers -productVersion", "r");
}

void teardown_platform(struct glug_plat *platform)
{
    if (platform)
    {
        if (platform->product_version)
            pclose(platform->product_version);
    }
}

enum glug_os os_plat(const struct glug_plat *platform)
{
    (void) platform;

    return os_mac();
}

void os_version_plat(const struct glug_plat *platform, struct glug_plat_version *version)
{
    (void) platform;

    if (version)
        os_version_mac(version);
}

void kernel_version_plat(const struct glug_plat *platform, struct glug_plat_version *version)
{
    (void) platform;

    if (version)
        kernel_version_mac(version);
}
#endif // GLUG_OS == GLUG_OS_MAC
