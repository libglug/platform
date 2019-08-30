#ifndef GLUG_PLATFORM_WIN32_H
#define GLUG_PLATFORM_WIN32_H

#include <glug/bool.h>
#include <glug/platform/os.h>
#include <glug/platform/version.h>

enum glug_os    (*get_os_win(void))(void);
bool            (*get_os_version_win(void))(struct glug_plat_version *);
bool            (*get_kernel_version_win(void))(struct glug_plat_version *);

#endif // GLUG_PLATFORM_WIN32_H
