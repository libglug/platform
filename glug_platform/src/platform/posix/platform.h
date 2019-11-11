#ifndef GLUG_SYSTEM_POSIX_H
#define GLUG_SYSTEM_POSIX_H

#include <glug/platform/os.h>
#include <glug/platform/version_t.h>

struct posix_context;

void    os_version_posix(struct glug_plat_version *, const struct posix_context *);
void    kernel_version_posix(struct glug_plat_version *, const struct posix_context *);

#endif // GLUG_SYSTEM_POSIX_H
