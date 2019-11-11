#ifndef GLUG_PLATFORM_WIN32_H
#define GLUG_PLATFORM_WIN32_H

#include <glug/platform/os.h>
#include <glug/platform/version_t.h>

struct win32_context;

enum glug_os    os_win(const struct win32_context *);
void            os_version_win(struct glug_plat_version *, const struct win32_context *);
void            kernel_version_win(struct glug_plat_version *, const struct win32_context *);

#endif // GLUG_PLATFORM_WIN32_H
