#include <getopt.h>
#include <string.h>
#include <ctype.h>

#include "misc_macros.h"
#include "getopt_usage.h"

void getopt_handle_error(char *argopts) {
	int i;

	for (i = 0; i < strlen(argopts); i++) {
		if (argopts[i] != optopt)
			continue;

		eprintf(
			"error: \033[31moption -%c requires an argument\033[0m\n",
			optopt
		);

		goto display_usage;
	}

	if (isprint(optopt))
		eprintf(
			"error: \033[31munknown option '-%c'\033[0m\n",
			optopt
		);
	else
		eprintf(
			"error: \033[31munknown option character '\\x%x'\033[0m\n",
			optopt
		);

display_usage:
	getopt_display_usage();
}
