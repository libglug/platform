#ifndef GLUG_PLATFORM_LINUX_H
#define GLUG_PLATFORM_LINUX_H

#include <glug/platform/os.h>
#include <glug/platform/version_t.h>

#include <stdio.h>

struct utsname;
typedef int (*uname_t)(struct utsname *);

enum glug_os    os_linux(void);

void            os_version_linux(struct glug_plat_version *);
void            os_version_lsb(FILE *, struct glug_plat_version *);

void            kernel_version_linux(FILE *, struct glug_plat_version *);
void            kernel_version_uname(const uname_t, struct glug_plat_version *);

#endif // GLUG_PLATFORM_LINUX_H
