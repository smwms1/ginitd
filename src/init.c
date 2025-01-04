#include <unistd.h>

#include "init_main.h"
#include "init_userspace.h"

int main(int argc, char **argv) {
	if (getpid() != 1)
		return init_userspace_main(argc, argv);

	return init_main(argc, argv);
}
