#include <sys/types.h>

#include "init_private.h"

sigset_t	init_signal_set;
int			init_pipe_fd;
pid_t		init_runlevel_script;
char		init_runlevel				= '0';
char		init_last_runlevel			= '0';
int			init_runlevel_is_stable		= 1;
