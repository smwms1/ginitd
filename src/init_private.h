#ifndef GINITD_INIT_PRIVATE_H
#define GINITD_INIT_PRIVATE_H

#include <sys/types.h>

extern sigset_t		init_signal_set;
extern int			init_pipe_fd;
extern pid_t		init_runlevel_script;
extern char			init_runlevel;
extern char			init_last_runlevel;
extern int			init_runlevel_is_stable;

#endif /* GINITD_INIT_PRIVATE_H */
