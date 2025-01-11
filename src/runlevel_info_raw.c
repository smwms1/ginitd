#include <stdio.h>
#include <errno.h>

#include "misc_macros.h"
#include "init_macros.h"
#include "init_comm_error.h"

int runlevel_info_get_raw(char *buffer, int len) {
	FILE	*fp;

	if (!fexists(INIT_RUNLEVEL_STAT)) {
		errno = EHOSTDOWN;
		goto comm_error;
	}

	fp = fopen(INIT_RUNLEVEL_STAT, "r");
	if (!fp)
		goto comm_error;

	fgets(buffer, len, fp);
	fclose(fp);

	return 0;

comm_error:
	init_comm_error();
	return -1;
}
