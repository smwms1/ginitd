#include "misc_macros.h"
#include "init_send_code.h"

int init_userspace_main(int argc, char **argv) {
	if (argc != 2) {
		eputs("init: incorrect arguments\n");
		return -1;
	}

	switch (argv[1][0]) {
		case '0':
			init_send_code("r:0             ");
			break;

		case '1':
		case 'S':
		case 's':
			init_send_code("r:1             ");
			break;

		case '2':
		case '3':
		case '4':
		case '5':
		case 'q':
		case 'Q':
		case 'u':
		case 'U':
			eputs("init: not supported, but allowed\n");
			break;

		case '6':
			init_send_code("r:6             ");
			break;

		default:
			eputs("init: not supported\n");
			return -1;
	}

	return 0;
}
