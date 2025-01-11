#include "logging.h"
#include "init_send_code.h"
#include "init_parse_code.h"

int init_parse_code(char code) {
	switch (code) {
		case '0':
			init_send_code("r:0");
			break;

		case '1':
		case 'S':
		case 's':
			init_send_code("r:1");
			break;

		case '3':
			init_send_code("r:3");
			break;

		case '2':
		case '4':
		case '5':
		case 'q':
		case 'Q':
		case 'u':
		case 'U':
			glogf('!', "not supported, but allowed");
			break;

		case '6':
			init_send_code("r:6");
			break;

		default:
			glogf('!', "not supported");
			return -1;
	}

	return 0;
}
