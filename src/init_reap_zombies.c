#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

#include "init_reap_zombies.h"

void init_reap_zombies(void) {
	pid_t pid;

	for (;;) {
		pid = waitpid(-1, NULL, WNOHANG);
		if (pid == 0)
			break;
		else if (pid == -1) {
			if (errno == ECHILD)
				break;
			perror("init: waitpid");
			continue;
		}
	}
}
