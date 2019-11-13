#ifndef GLUG_PLATFORM_NULL_H
#define GLUG_PLATFORM_NULL_H

#include <glug/platform/os.h>
#include <glug/platform/version_t.h>

enum glug_os    os_null(void);
void            os_version_null(void);
void            kernel_version_null(void);

#endif // GLUG_PLATFORM_NULL_H
