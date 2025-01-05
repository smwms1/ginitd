#include <stdio.h>
#include <stdarg.h>
#include <syslog.h>

#include "misc_macros.h"
#include "logging_write.h"
#include "logging_logf.h"

void glogf(char pri, char *format, ...) {
	va_list args;
	int priority;
	static char final[216];

	switch (pri) {
		case '!':
			priority = LOG_CRIT;
			break;

		/* 
			NOTE: refrain from using 'w' in source code. This is an init system/
			  system service manager, all errors are critical. 'w' should *only*
			  be used when the situation is perfectly fine, or could easily turn
			  out to be perfectly fine. Exempli gratia:

			  		int fd;
					int count;

					count = 0;

				reopen:
					fd = open("/myfile", O_RDWR);
					if (fd == -1) {
						if (count > 5)
							goto error;
						
						glogf('w', "could not open file /myfile, retrying...");
						                                         ^^^^^^^^
						count++;
						sleep(1);
					}

					return fd;

				error:
					glogerr("could not open file /myfile");

			  It's precisely the fact that you're *retrying* the operation, and
			  everything could be perfectly fine if it works the second time
			  (or third, or fourth, or fifth time) around. You should also call
			  glogerr at the end to tell the user exactly what went wrong.
		*/
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
