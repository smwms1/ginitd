#ifndef GINITD_RUNLEVEL_INFO_H
#define GINITD_RUNLEVEL_INFO_H

#include <sys/types.h>

struct runlevel_info {
	char	runlevel;
	char	runlevel_last;
	int		is_stable;
	pid_t	runlevel_pid;
};

struct runlevel_info runlevel_info_get(void);

#endif /* GINITD_RUNLEVEL_INFO_H */
