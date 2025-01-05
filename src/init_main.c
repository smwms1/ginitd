#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

#include "misc_macros.h"
#include "init_macros.h"
#include "init_private.h"
#include "init_runlevel_script.h"
#include "init_reap_zombies.h"
#include "init_read_code.h"
#include "init_handle_selinux.h"

int init_main(int argc, char **argv) {
	eputs("init: booting...\n");

	init_handle_selinux(argv[0]);

	chdir("/");
	mkdir("/run/init", 0770);

	sigfillset(&init_signal_set);
	sigdelset(&init_signal_set, SIGTERM);
	sigprocmask(SIG_BLOCK, &init_signal_set, NULL);

	// Set up the communication channel
	mkfifo(INIT_PID1_PIPE, 0660);
	init_pipe_fd = open(INIT_PID1_PIPE, O_RDONLY | O_NONBLOCK);

	// Boot up to runlevel '3'
	init_spawn_runlevel_script('3');

	while (1) {
		init_reap_zombies();
		init_read_code();
		sleep(INIT_MAINLOOP_WAIT);
	}
}
