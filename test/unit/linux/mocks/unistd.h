#ifndef UNIT_UNISTD_H
#define UNIT_UINSTD_H

#include <stdio.h>

void set_lscpu_output(const char *);
void set_lscpu_failure(int);

FILE *popen(const char *, const char *);
int pclose(FILE *);

#endif
