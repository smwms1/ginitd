#ifndef GINITD_LOGGING_INIT_H
#define GINITD_LOGGING_INIT_H

#include <syslog.h>

/*
	I've often found myself wondering which syslog facility to use, so here is
	a definitive decision for ginitd:

	* Userspace programs, however important, use LOG_USER
	* Most daemons (e.g supervise) will use LOG_DAEMON
	* init and runlevel-start will write to syslog under LOG_DAEMON, but will
	  also copy the contents that they write to a file /run/init/init.log, in
	  case syslog is not available.

	The point of this is so that, even in very early boot, we can log messages,
	and they can be read later on.
*/

#define LOGGING_FACIL_INIT		578
#define LOGGING_FACIL_DAEMON	LOG_DAEMON
#define LOGGING_FACIL_USER		LOG_USER

void logging_init(char *name, int syslog_facil);

#endif /* GINITD_LOGGING_INIT_H */
