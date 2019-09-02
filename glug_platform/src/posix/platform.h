#ifndef GLUG_SYSTEM_POSIX_H
#define GLUG_SYSTEM_POSIX_H

#include <glug/bool.h>
#include <glug/platform/os.h>
#include <glug/platform/version.h>


enum glug_os    os_posix(void);
glug_bool       os_version_posix(struct glug_plat_version *);
glug_bool       kernel_version_posix(struct glug_plat_version *);

#endif // GLUG_SYSTEM_POSIX_H
