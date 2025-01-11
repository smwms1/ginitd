#include "cli_macros.h"
#include "logging.h"
#include "runlevel_main.h"

int main(int argc, char **argv) {
	CLI_ARGS_SETUP();

	logging_init(LOGGING_FACIL_USER);

	runlevel_main();
}
