#include <errno.h>
#include <string.h>

#include "logging_errno.h"
#include "logging_logf.h"

void glogerr(char *msg) {
	glogf('!', "%s: %s", msg, strerror(errno));
}
