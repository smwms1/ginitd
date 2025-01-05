#include <stdio.h>

#include "init_macros.h"
#include "logging.h"

int runlevel_info_get_raw(char *buffer, int len) {
	FILE	*fp;

	fp = fopen(INIT_RUNLEVEL_STAT, "r");
	if (!fp) {
		glogf('!', "could not read runlevel file");
		return -1;
	}

	fgets(buffer, len, fp);
	fclose(fp);

	return 0;
}
