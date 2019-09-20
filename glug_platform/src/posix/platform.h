#ifndef GLUG_SYSTEM_POSIX_H
#define GLUG_SYSTEM_POSIX_H

#include <glug/bool.h>
#include <glug/platform/os.h>
#include <glug/platform/version_t.h>

struct posix_context;

enum glug_os    os_posix(const struct posix_context *);
glug_bool       os_version_posix(struct glug_plat_version *, const struct posix_context *);
glug_bool       kernel_version_posix(struct glug_plat_version *, const struct posix_context *);

#endif // GLUG_SYSTEM_POSIX_H
