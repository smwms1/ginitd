#include <errno.h>

#include "logging.h"
#include "misc_macros.h"
#include "init_macros.h"
#include "init_comm_error.h"

void init_comm_error(void) {
	glogerr("communication failed");

	// See the Practical systemd section in https://suckless.org/sucks/systemd/
	// for why I did this.
	if (errno == EPERM)
		eputs(INIT_EPERM_ERROR);
	else if (errno == EHOSTDOWN)
		eputs(INIT_EHOSTDOWN_ERROR);
}
