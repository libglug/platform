#include "platform_platform.h"

#include <glug/os.h>

#if defined(GLUG_OS_WIN)

#include "win32/platform.h"

enum glug_os (*(*get_os_fcn)(void))(void) = get_os_win;
bool (*(*get_os_version_fcn)(void))(struct glug_plat_version *) = get_os_version_win;
bool (*(*get_kernel_version_fcn)(void))(struct glug_plat_version *) = get_kernel_version_win;

#elif defined(GLUG_OS_MAC)

#include "macos/platform.h"

enum glug_os (*(*get_os_fcn)(void))(void) = get_os_mac;
bool (*(*get_os_version_fcn)(void))(struct glug_plat_version *) = get_os_version_mac;
bool (*(*get_kernel_version_fcn)(void))(struct glug_plat_version *) = get_kernel_version_mac;

#elif  defined(GLUG_OS_LIN)

#include "linux/platform.h"

enum glug_os (*(*get_os_fcn)(void))(void) = get_os_linux;
bool (*(*get_os_version_fcn)(void))(struct glug_plat_version *) = get_os_version_linux;
bool (*(*get_kernel_version_fcn)(void))(struct glug_plat_version *) = get_kernel_version_linux;

#elif defined (GLUG_OS_BSD)

#include "bsd/platform.h"

enum glug_os (*(*get_os_fcn)(void))(void) = get_os_bsd;
bool (*(*get_os_version_fcn)(void))(struct glug_plat_version *) = get_os_version_bsd;
bool (*(*get_kernel_version_fcn)(void))(struct glug_plat_version *) = get_kernel_version_bsd;

#endif
