#ifndef GLUG_PLATFORM_BSD_H
#define GLUG_PLATFORM_BSD_H

#include <glug/platform/os.h>
#include <glug/platform/version_t.h>

enum glug_os    os_bsd(void);
void            os_version_bsd(struct glug_plat_version *);
void            kernel_version_bsd(struct glug_plat_version *);

#endif // GLUG_PLATFORM_BSD_H
