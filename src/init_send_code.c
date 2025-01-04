#include <stdio.h>

#include "misc_macros.h"
#include "init_macros.h"
#include "init_send_code.h"

int init_send_code(char *code) {
	if (fexists(INIT_PID1_PIPE))
		goto comm_error;

	FILE *fp	= fopen(INIT_PID1_PIPE, "w");

	if (!fp)
		goto comm_error;

	fputs(code, fp);
	fclose(fp);

	return 0;

comm_error:
	eputs("init: communication failed\n");
	return -1;
}
