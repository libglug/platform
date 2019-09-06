#ifndef MOCK_UNISTD_H
#define MOCK_UNISTD_H

#include <stdio.h>

void set_popen_output(const char *);
void set_popen_failure_count(int);

FILE *popen(const char *, const char *);
int pclose(FILE *);

#endif // MOCK_UNISTD_H
