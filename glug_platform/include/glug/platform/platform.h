#ifndef GLUG_PLATFORM_H
#define GLUG_PLATFORM_H

#include <glug/import.h>
#include <glug/extern.h>

#include <glug/platform/os.h>
#include <glug/platform/version_t.h>

GLUG_EXTERN_START

struct glug_plat;
#ifdef GLUG_USE_TYPEDEFS
    typedef struct glug_plat glug_plat_t;
#endif

GLUG_LIB_API struct glug_plat * glug_plat_create(void);
GLUG_LIB_API struct glug_plat * glug_plat_free(struct glug_plat *);

GLUG_LIB_API enum glug_os       glug_plat_os(const struct glug_plat *);
GLUG_LIB_API void               glug_plat_os_version(const struct glug_plat *, struct glug_plat_version *);
GLUG_LIB_API void               glug_plat_kernel_version(const struct glug_plat *, struct glug_plat_version *);

GLUG_EXTERN_END

#endif // GLUG_PLATFORM_H
