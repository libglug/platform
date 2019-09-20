#ifndef GLUG_PLATFORM_MACOS_H
#define GLUG_PLATFORM_MACOS_H

#include <glug/bool.h>
#include <glug/platform/os.h>
#include <glug/platform/version_t.h>

struct macos_context;

enum glug_os    os_mac(const struct macos_context *);
glug_bool       os_version_mac(struct glug_plat_version *, const struct macos_context *);
glug_bool       kernel_version_mac(struct glug_plat_version *, const struct macos_context *);

glug_bool       responds_to_osversion(void);
glug_bool       os_version_fallback_mac(struct glug_plat_version *, const struct macos_context *);

#endif // GLUG_PLATFORM_MACOS_H
