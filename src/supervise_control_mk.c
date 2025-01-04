#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

#include "misc_macros.h"
#include "supervise_control_mk.h"
#include "supervise_private.h"
#include "supervise_macros.h"
#include "path_concat.h"

int supervise_make_control(void) {
	char *control_path;

	control_path = path_concat(supervise_tempdir_path, SUPERVISE_CTRL_PIPE);
	if (mkfifo(control_path, 660) == -1)
		goto report_error;

	supervise_control	= open(SUPERVISE_CTRL_PIPE, O_RDONLY | O_NONBLOCK);
	
	if (supervise_control == -1)
		goto report_error;

report_error:
	eputs("supervise: could not connect to control pipe\n");
	exit(1);
}
