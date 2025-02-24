#include <unistd.h>

#include "logging.h"
#include "init_private.h"
#include "init_runlevel_script.h"
#include "init_read_code.h"

int init_read_code(void) {
	static char code[17];
	size_t bytes;

	bytes = read(init_pipe_fd, code, 16);
	code[16] = '\0';

	// There was nothing to read.
	if (bytes == 0)
		return 0;

	if (bytes != 16)
		goto processing_error;

	if (code[1] != ':')
		goto processing_error;

	switch (code[0]) {
		// [r]unlevel
		case 'r':
			if (code[2] == init_runlevel) {
				glogf('n', "runlevel is already %d, doing nothing", init_runlevel);
				break;
			}

			glogf('n', "changing runlevel to %d", code[2]);
			init_spawn_runlevel_script(code[2]);
			break;

		default:
			goto processing_error;
	}

	return 0;

processing_error:
	glogf('w', "invalid request");
	return -1;
}
