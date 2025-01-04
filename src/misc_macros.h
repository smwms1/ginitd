#ifndef GINITD_H
#define GINITD_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define streq(a,b)		(strcmp(a, b) == 0)
#define eprintf(...)	fprintf(stderr, __VA_ARGS__)
#define eputs(s)		fputs(s, stderr)
#define eputc(c)		fputc(c, stderr)
#define fexists(p)		(access(INIT_PID1_PIPE, F_OK) != 0)

#endif /* GINITD_H */
