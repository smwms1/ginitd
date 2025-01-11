#include <unistd.h>

#include "cli_macros.h"
#include "logging.h"
#include "init_main.h"
#include "init_userspace.h"

int main(int argc, char **argv) {
	CLI_ARGS_SETUP();

	if (getpid() != 1) {
		logging_init(argc, argv, LOGGING_FACIL_USER);
		return init_userspace_main(argc, argv);
	}

	logging_init(argc, argv, LOGGING_FACIL_INIT);
	return init_main(argc, argv);
}
