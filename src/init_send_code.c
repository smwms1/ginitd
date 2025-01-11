#include <asm-generic/errno.h>
#include <stdio.h>
#include <unistd.h>
#include "errno.h"

#include "misc_macros.h"
#include "init_macros.h"
#include "init_send_code.h"
#include "init_comm_error.h"

int init_send_code(char *code) {
	if (!fexists(INIT_PID1_PIPE)) {
		errno = EHOSTDOWN;
		goto comm_error;
	}

	FILE *fp	= fopen(INIT_PID1_PIPE, "w");

	if (!fp)
		goto comm_error;

	fprintf(fp, "%-16s", code);
	fclose(fp);

	return 0;

comm_error:
	init_comm_error();
	return -1;
}
