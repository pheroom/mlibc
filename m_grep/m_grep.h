#ifndef M_GREP_H
#define M_GREP_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ERROR_01 "m_grep: %s: No such file or directory\n"
#define ERROR_02 "m_grep: invalid option -- '%c'\n"
#define ERROR_03 "m_grep: arguments must be 2 or more\n"

#define BUFFER_SIZE 512

typedef char PATTERNS[10][100];
typedef char FILES[10][100];

char* toLower(char* s);
void processFile(char *, PATTERNS, int, int *, int *);

#endif //M_GREP_H
