#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <syslog.h>

#include "misc_macros.h"
#include "logging_private.h"
#include "logging_write.h"

void logging_write(int priority, char *msg) {
	static char	fullstr[256];
	time_t tm;

	sprintf(fullstr, "%s[%d]: %s", logging_name, getpid(), msg);

	// LOGGING to CONSOLE
	eprintf("%s\n", fullstr);

	// LOGGING through init's log
	if (logging_init_log) {
		time(&tm);
		fprintf(logging_init_log, "%ld: %s\n", tm, fullstr);
		fflush(logging_init_log);
	}

	// LOGGING to SYSLOG
	// syslog already includes the PID and name
	syslog(priority, "%s", msg);
}
