#ifndef GLUG_PLATFORM_H
#define GLUG_PLATFORM_H

#include <glug/import.h>
#include <glug/extern.h>
#include <glug/bool.h>

#include <glug/platform/platform_t.h>
#include <glug/platform/os.h>
#include <glug/platform/version_t.h>

GLUG_EXTERN_START

GLUG_LIB_API struct glug_plat * glug_plat_create(void);
GLUG_LIB_API struct glug_plat * glug_plat_free(struct glug_plat *);

GLUG_LIB_API enum glug_os       glug_plat_os(struct glug_plat *);
GLUG_LIB_API glug_bool          glug_plat_os_version(struct glug_plat *, struct glug_plat_version *);
GLUG_LIB_API glug_bool          glug_plat_kernel_version(struct glug_plat *, struct glug_plat_version *);

GLUG_EXTERN_END

#endif // GLUG_PLATFORM_H
