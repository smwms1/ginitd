#include <string.h>

#include "getopt_private.h"
#include "misc_macros.h"

void getopt_set_usage(char *_usage_str) {
	strcpy(usage_str, _usage_str);
}

void getopt_display_usage(void) {
	eputs(usage_str);
}
