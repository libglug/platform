#ifndef GLUG_PLATFORM_H
#define GLUG_PLATFORM_H

#include <glug/import.h>
#include <glug/extern.h>

#include <glug/platform/os.h>
#include <glug/platform/version.h>

GLUG_EXTERN_START

GLUG_LIB_API enum glug_os           glug_plat_get_os(void);
GLUG_LIB_API struct glug_os_version glug_plat_os_version(void);

GLUG_EXTERN_END

#endif // GLUG_PLATFORM_H
