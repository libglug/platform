#ifndef GLUG_PLATFORM_WIN32_H
#define GLUG_PLATFORM_WIN32_H

#include <glug/bool.h>
#include <glug/platform/os.h>
#include <glug/platform/version_t.h>

enum glug_os    os_win(void);
glug_bool       os_version_win(struct glug_plat_version *);
glug_bool       kernel_version_win(struct glug_plat_version *);

#endif // GLUG_PLATFORM_WIN32_H
