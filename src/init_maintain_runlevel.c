#include <stdio.h>

#include "logging.h"
#include "init_private.h"
#include "init_macros.h"

int init_maintain_runlevel(void) {
	FILE	*runlevel_file;

	runlevel_file = fopen(INIT_RUNLEVEL_STAT, "w");
	if (!runlevel_file) {
		glogf('!', "failed to update runlevel on disk");
		return -1;
	}

	if (init_runlevel_is_stable)
		fprintf(
			runlevel_file,
			"%c %c <stable> 0\n",
			init_runlevel,
			init_last_runlevel
		);
	else
		fprintf(
			runlevel_file,
			"%c %c <unstable> %d\n",
			init_runlevel,
			init_last_runlevel,
			init_runlevel_script
		);

	fclose(runlevel_file);

	return 0;
}
