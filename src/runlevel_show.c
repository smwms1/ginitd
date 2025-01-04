#include <stdio.h>

#include "runlevel_info.h"

void runlevel_show(struct runlevel_info info) {
	printf("%c %c\n", info.runlevel_last, info.runlevel);
}
