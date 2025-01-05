#include "logging.h"
#include "init_userspace.h"

int main(int argc, char **argv) {
	logging_init("telinit", LOGGING_FACIL_USER);
	return init_userspace_main(argc, argv);
}
