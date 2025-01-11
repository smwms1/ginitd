#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>

#include "getopt_args.h"
#include "getopt_args_error.h"
#include "getopt_error.h"
#include "getopt_init.h"
#include "getopt_usage.h"
#include "misc_macros.h"
#include "init_macros.h"
#include "init_parse_code.h"
#include "init_userspace.h"

int init_userspace_main(int argc, char **argv) {
	int c;
	char code;

	getopt_init();
	getopt_set_usage(INIT_USAGE);

	while ((c = getopt(argc, argv, "hr")) != -1) {
		switch (c) {
		case 'h':
			getopt_display_usage();
			eputs("\n" INIT_USAGE_EXTENDED);
			return 0;
		
		case '?':
			getopt_handle_error("");
		
		default:
			abort();
		}
	}

	if (getopt_args_remaining() != 1)
		getopt_handle_args_error(1);

	code = argv[getopt_args_starts_at() + 1][0];

	init_parse_code(code);

	return 0;
}
