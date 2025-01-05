#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <syslog.h>

#include "misc_macros.h"
#include "logging_private.h"

void logging_write(int priority, char *msg) {
	static char	fullstr[256];
	time_t tm;

	sprintf(fullstr, "%s[%d]: %s", logging_name, getpid(), msg);

	time(&tm);
	eprintf("%s\n", fullstr);
	if (logging_init_log)
		fprintf(logging_init_log, "%ld: %s\n", tm, fullstr);
	// syslog already includes the PID and name
	syslog(priority, "%s", msg);
}
