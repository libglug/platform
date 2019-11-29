#ifndef GLUG_PLATFORM_NULL_H
#define GLUG_PLATFORM_NULL_H

#include <glug/platform/os.h>
#include <glug/platform/version_t.h>

GLUG_LIB_LOCAL enum glug_os os_null(void);
GLUG_LIB_LOCAL void         os_version_null(void);
GLUG_LIB_LOCAL void         kernel_version_null(void);

#endif // GLUG_PLATFORM_NULL_H
