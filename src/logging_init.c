#include <string.h>
#include <sys/syslog.h>
#include <syslog.h>
#include <libgen.h>

#include "logging_init.h"
#include "logging_macros.h"
#include "logging_private.h"

void logging_init(int argc, char **argv, int syslog_facil) {
	strcpy(logging_name, basename(argv[0]));
	
	logging_init_log = NULL;

	openlog(
		logging_name,
		LOG_PID
		// Ensure that the opening of the log is delayed; until an syslog
		// daemon is called, there will be nothing to connect.
		| LOG_ODELAY,
		syslog_facil == LOGGING_FACIL_INIT
		? LOGGING_FACIL_DAEMON
		: syslog_facil
	);

	if (syslog_facil == LOGGING_FACIL_INIT) {
		logging_init_log = fopen(LOGGING_INIT_LOG_PATH, "w");
		if (!logging_init_log)
			perror("WARNING: could not open initial log");
	}
}
