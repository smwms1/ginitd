#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

#include "init_private.h"
#include "init_reap_zombies.h"
#include "init_maintain_runlevel.h"

void init_reap_zombies(void) {
	pid_t pid;

	for (;;) {
		pid = waitpid(-1, NULL, WNOHANG);
		if (pid == init_runlevel_script) {
			init_runlevel_is_stable	= 1;
			init_maintain_runlevel();
		}
		else if (pid == 0)
			break;
		else if (pid == -1) {
			if (errno == ECHILD)
				break;
			perror("init: waitpid");
			continue;
		}
	}
}
