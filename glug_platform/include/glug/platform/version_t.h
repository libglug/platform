#ifndef GLUG_PLATFORM_VERSION_T_H
#define GLUG_PLATFORM_VERSION_T_H

#include <stdint.h>

struct glug_plat_version {
    uint32_t major;
    uint32_t minor;
    uint32_t patch;
};

#ifdef GLUG_USE_TYPEDEFS
    typedef struct glug_plat_version glug_plat_version_t;
#endif

#endif // GLUG_PLATFORM_VERSION_T_H
