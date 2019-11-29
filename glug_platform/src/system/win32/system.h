#ifndef GLUG_SYSTEM_WIN32_H
#define GLUG_SYSTEM_WIN32_H

#include <stdint.h>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

typedef void (*GetNSInfo_t)(LPSYSTEM_INFO);
typedef void (*GetPISMemory_t)(PULONGLONG);

GLUG_LIB_LOCAL uint32_t cpus_win(GetNSInfo_t);
GLUG_LIB_LOCAL uint32_t active_cpus_win(GetNSInfo_t);
GLUG_LIB_LOCAL uint64_t physical_mem_win(GetPISMemory_t);

#endif // GLUG_SYSTEM_WIN32_H
