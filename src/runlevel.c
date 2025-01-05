#include "logging.h"
#include "runlevel_main.h"

int main(int argc, char **argv) {
	logging_init(argc, argv, LOGGING_FACIL_USER);

	runlevel_main(argc, argv);
}
