#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>

#include "misc_macros.h"
#include "getopt_error.h"
#include "getopt_init.h"
#include "getopt_usage.h"
#include "runlevel_info.h"
#include "runlevel_macros.h"
#include "runlevel_main.h"
#include "runlevel_show_sysv.h"
#include "runlevel_show_tty.h"

int runlevel_main(int argc, char **argv) {
	int c;
	struct runlevel_info info;

	getopt_init();
	getopt_set_usage(RUNLEVEL_USAGE);

	while ((c = getopt (argc, argv, "h")) != -1) {
		switch (c) {
		case 'h':
			getopt_display_usage();
			eputs("\n" RUNLEVEL_USAGE_EXTENDED);
			return 0;
		
		case '?':
			getopt_handle_error("");
			return 1;
		
		default:
			abort();
		}
	}

	info = runlevel_info_get();

	if (info.is_stable == -1)
		return -1;

	if (isatty(STDOUT_FILENO))
		runlevel_show_tty(info);
	else
		runlevel_show_sysv(info);

	return 0;
}
