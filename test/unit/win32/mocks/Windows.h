#ifndef MOCK_WINDOWS_H
#define MOCK_WINDOWS_H

#include <stdio.h>

typedef unsigned long long ULONGLONG;
typedef struct SYSTEM_INFO {
    unsigned long dwNumberOfProcessors;
    unsigned long long dwActiveProcessorMask;
} SYSTEM_INFO;

void set_system_cpus(unsigned long, unsigned long long);
void GetNativeSystemInfo(SYSTEM_INFO *);

void set_memory(unsigned long long);
void set_memory_failure_count(int);
int GetPhysicallyInstalledSystemMemory(unsigned long long *);

#endif // MOCK_WINDOWS_H
