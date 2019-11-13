#include <glug/platform/platform.h>
#include "platform_builder.h"
#include "null/platform.h"

#include <stdlib.h>
#include <string.h>

static enum glug_os get_os_null(const plat_context *context)
{
    (void) context;

    return os_null();
}

static void get_os_version_null(struct glug_plat_version *version, const plat_context *context)
{
    (void) version;
    (void) context;

    os_version_null();
}

static void get_kernel_version_null(struct glug_plat_version *version, const plat_context *context)
{
    (void) version;
    (void) context;

    kernel_version_null();
}

struct glug_plat *glug_plat_create(void)
{
    struct glug_plat *plat = malloc(sizeof(struct glug_plat));
    if (plat)
    {
        plat->os = get_os_null;
        plat->os_version = get_os_version_null;
        plat->kernel_version = get_kernel_version_null;
        build_platform(plat);
    }

    return plat;
}

struct glug_plat *glug_plat_free(struct glug_plat *platform)
{
    teardown_platform(platform);
    if (platform)
        free(platform);

    return NULL;
}

enum glug_os glug_plat_os(struct glug_plat *plat)
{
    return plat->os(&plat->plat_context);
}

void glug_plat_os_version(struct glug_plat *plat, struct glug_plat_version *version)
{
    memset(version, 0, sizeof(struct glug_plat_version));
    plat->os_version(version, &plat->plat_context);
}

void glug_plat_kernel_version(struct glug_plat *plat, struct glug_plat_version *version)
{
    memset(version, 0, sizeof(struct glug_plat_version));
    plat->kernel_version(version, &plat->plat_context);
}
