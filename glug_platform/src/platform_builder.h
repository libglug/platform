#ifndef GLUG_PLATFORM_PLATFORM_H
#define GLUG_PLATFORM_PLATFORM_H

#include <glug/platform/os.h>
#include <glug/platform/version_t.h>

#include <glug/bool.h>

struct glug_plat
{
    enum glug_os (*os)(void);
    glug_bool    (*os_version)(struct glug_plat_version *);
    glug_bool    (*kernel_version)(struct glug_plat_version *);
};

void build_platform(struct glug_plat *);

#endif // GLUG_PLATFORM_PLATFORM_H
