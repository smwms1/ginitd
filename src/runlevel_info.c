#include <stdio.h>

#include "misc_macros.h"
#include "init_macros.h"
#include "runlevel_info.h"

struct runlevel_info runlevel_info_get(void) {
	FILE	*fp;
	char	stability[16];
	struct runlevel_info info;

	fp = fopen(INIT_RUNLEVEL_STAT, "r");
	if (!fp) {
		eputs("runlevel: could not read runlevel file\n");
		info.is_stable	= -1;
		return info;
	}

	fscanf(
		fp,
		"%c %c %15s",
		&info.runlevel,
		&info.runlevel_last,
		stability
	);

	if (streq(stability, "<stable>"))
		info.is_stable = 1;
	else if (streq(stability, "<unstable>"))
		info.is_stable = 0;
	else {
		eputs("runlevel: could not read stability\n");
		info.is_stable = -1;
	}

	fclose(fp);
	
	return info;
}
