#include <stdio.h>

#include "runlevel_info.h"

void runlevel_show_tty(struct runlevel_info info) {
	if (info.is_stable) {
		printf(
			"\033[1mSystem is stable.\033[0m\n"
			"(previously): \033[1;90m%c\033[0m\n"
			"runlevel:     \033[1;32m%c\033[0m\n",
			info.runlevel_last,
			info.runlevel
		);
	} else {
		printf(
			"\033[1mSystem is changing state!\033[0m\n"
			"from:         \033[1;90m%c\033[0m\n"
			"to:           \033[1;35m%c\033[0m\n",
			info.runlevel_last,
			info.runlevel
		);
	}
}
