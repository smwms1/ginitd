#include <stdio.h>
#include <stdarg.h>
#include <syslog.h>

#include "misc_macros.h"
#include "logging_write.h"

void glogf(char pri, char *format, ...) {
	va_list args;
	int priority;
	static char final[216];

	switch (pri) {
		case '!':
			priority = LOG_CRIT;
			break;

		case 'w':
			priority = LOG_WARNING;
			break;
		
		case 'n':
			priority = LOG_NOTICE;
			break;
		
		case 'i':
			priority = LOG_INFO;
			break;
		
		case 'd':
			priority = LOG_DEBUG;
			break;

		default:
			eprintf("WARNING: priority '%c' not supported", pri);
			priority = LOG_INFO;
	}

	va_start(args, format);
	vsprintf(final, format, args);

	logging_write(priority, final);

	va_end(args);
}
