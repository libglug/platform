#ifndef POSIX_PLATFORM_CONTEXT_H
#define POSIX_PLATFORM_CONTEXT_H

struct utsname;
struct posix_context
{
    int (*uname)(struct utsname *);
};

#endif // POSIX_PLATFORM_CONTEXT_H
