#ifndef MLIBC_M_CAT_H
#define MLIBC_M_CAT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_01 "m_cat: %s: No such file or directory\n"
#define ERROR_02 "m_cat: invalid option -- '%c'\n"

void processFile(char *, int *, int *);

#endif //MLIBC_M_CAT_H
