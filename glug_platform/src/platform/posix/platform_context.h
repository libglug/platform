#ifndef POSIX_PLATFORM_CONTEXT_H
#define POSIX_PLATFORM_CONTEXT_H

#include <stdio.h>

struct utsname;
struct posix_context
{
    int (*uname)(struct utsname *);
    FILE *lsb_release;
};

#endif // POSIX_PLATFORM_CONTEXT_H
