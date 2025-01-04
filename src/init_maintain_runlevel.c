#include <stdio.h>

#include "misc_macros.h"
#include "init_private.h"
#include "init_macros.h"

int init_maintain_runlevel(void) {
	FILE	*runlevel_file;

	runlevel_file = fopen(INIT_RUNLEVEL_STAT, "w");
	if (!runlevel_file) {
		eputs("init: failed to update runlevel on disk.\n");
		return -1;
	}

	if (init_runlevel_is_stable)
		fprintf(
			runlevel_file,
			"%c %c <stable>\n",
			init_runlevel,
			init_last_runlevel
		);
	else
		fprintf(
			runlevel_file,
			"%c %c <unstable>\n",
			init_runlevel,
			init_last_runlevel
		);

	fclose(runlevel_file);

	return 0;
}
