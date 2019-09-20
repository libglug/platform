#ifndef GLUG_PLATFORM_LINUX_H
#define GLUG_PLATFORM_LINUX_H

#include <glug/bool.h>
#include <glug/platform/os.h>
#include <glug/platform/version_t.h>

struct linux_context;

enum glug_os    os_linux(const struct linux_context *);
glug_bool       os_version_linux(struct glug_plat_version *, const struct linux_context *);
glug_bool       kernel_version_linux(struct glug_plat_version *, const struct linux_context *);

#endif // GLUG_PLATFORM_LINUX_H
