#include <stdio.h>

#include "misc_macros.h"
#include "runlevel_info.h"
#include "runlevel_info_raw.h"
#include "runlevel_macros.h"

struct runlevel_info runlevel_info_get(void) {
	char	buffer[RUNLEVEL_BUFSIZE];
	char	stability[16];
	struct runlevel_info info;

	if (runlevel_info_get_raw(buffer, RUNLEVEL_BUFSIZE - 1) == -1) {
		info.is_stable	= -1;
		return info;
	}

	sscanf(
		buffer,
		"%c %c %15s %d",
		&info.runlevel,
		&info.runlevel_last,
		stability,
		&info.runlevel_pid
	);

	if (streq(stability, "<stable>"))
		info.is_stable = 1;
	else if (streq(stability, "<unstable>"))
		info.is_stable = 0;
	else {
		eputs("runlevel: could not read stability\n");
		info.is_stable = -1;
	}
	
	return info;
}
