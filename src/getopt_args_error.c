#include <stdlib.h>

#include "misc_macros.h"
#include "getopt_usage.h"
#include "getopt_args.h"
#include "getopt_args_error.h"

void getopt_handle_args_error(int wanted) {
	eprintf(
		"error: \033[31mgot %d args, wanted %d\033[0m\n",
		getopt_args_remaining(),
		wanted
	);

	getopt_display_usage();
	exit(-1);
}
