#ifndef GLUG_SYSTEM_WIN32_H
#define GLUG_SYSTEM_WIN32_H

#include <stdint.h>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

typedef void (*GetNSInfo_t)(LPSYSTEM_INFO);
typedef void (*GetPISMemory_t)(PULONGLONG);

uint32_t    cpus_win(GetNSInfo_t);
uint32_t    active_cpus_win(GetNSInfo_t);
uint64_t    physical_mem_win(GetPISMemory_t);

#endif // GLUG_SYSTEM_WIN32_H
