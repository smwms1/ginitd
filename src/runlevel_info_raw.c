#include <stdio.h>

#include "misc_macros.h"
#include "init_macros.h"

int runlevel_info_get_raw(char *buffer, int len) {
	FILE	*fp;

	fp = fopen(INIT_RUNLEVEL_STAT, "r");
	if (!fp) {
		eputs("runlevel: could not read runlevel file\n");
		return -1;
	}

	fgets(buffer, len, fp);
	fclose(fp);

	return 0;
}
