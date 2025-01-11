#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>

#include "misc_macros.h"
#include "cli_args.h"
#include "getopt_error.h"
#include "getopt_init.h"
#include "getopt_usage.h"
#include "runlevel_info.h"
#include "runlevel_info_raw.h"
#include "runlevel_macros.h"
#include "runlevel_main.h"
#include "runlevel_show.h"

int runlevel_main(void) {
	int c;
	int r;
	struct runlevel_info info;

	r = 0;

	getopt_init();
	getopt_set_usage(RUNLEVEL_USAGE);

	while ((c = getopt(cli_argc, cli_argv, "hr")) != -1) {
		switch (c) {
		case 'h':
			getopt_display_usage();
			eputs("\n" RUNLEVEL_USAGE_EXTENDED);
			return 0;

		case 'r':
			r = 1;
			break;
		
		case '?':
			getopt_handle_error("");
			return 1;
		
		default:
			abort();
		}
	}

	if (r) {
		char buffer[RUNLEVEL_BUFSIZE];

		if (runlevel_info_get_raw(buffer, RUNLEVEL_BUFSIZE - 1) == -1)
			return -1;

		fputs(buffer, stdout);
	}
	else {
		info = runlevel_info_get();

		if (info.is_stable == -1)
			return -1;

		runlevel_show(info);
	}

	return 0;
}
