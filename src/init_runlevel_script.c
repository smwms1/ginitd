#include <unistd.h>
#include <signal.h>
#include <stdio.h>

#include "init_macros.h"
#include "init_private.h"
#include "init_maintain_runlevel.h"

int init_spawn_runlevel_script(char runlevel) {
	// Update the internal runlevel.
	init_last_runlevel		= init_runlevel;
	init_runlevel			= runlevel;
	init_runlevel_is_stable = 0;
	init_maintain_runlevel();

	init_runlevel_script = vfork();
	
	switch (init_runlevel_script) {
		case 0:
			sigprocmask(SIG_UNBLOCK, &init_signal_set, NULL);
			setsid();
			execl(
				INIT_RC_RUNLEVEL_SC,
				INIT_RC_RUNLEVEL_SC,
				(char[]){runlevel, '\0'},
				NULL
			);
			perror("init: execvp");
			_exit(1);
		
		case -1:
			perror("init: fork");
			return -255;
    }

	return 0;
}
