#include "platform.h"
#include "platform_context.h"

#include <stdio.h>

enum glug_os os_linux(const struct linux_context *context)
{
    (void) context;
    return glug_os_linux;
}

void os_version_linux(struct glug_plat_version *version, const struct linux_context *context)
{
    (void) version;
    (void) context;
}

void kernel_version_linux(struct glug_plat_version *version, const struct linux_context *context)
{
    FILE *proc_version = context->proc_version;

    fseek(proc_version, 0, SEEK_SET);
    fscanf(proc_version, "%*[^0-9] %u.%u.%u", &version->major, &version->minor, &version->patch);
}
