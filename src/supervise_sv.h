#ifndef GINITD_SUPERVISE_SV_H
#define GINITD_SUPERVISE_SV_H

#include <sys/types.h>
#include <stdio.h>

struct supervise_sv {
	// Path of shell script
	char	path[64];

	// Runtime information storage
	FILE	*status_fp;

	enum supervise_sv_status {
		SUPERVISE_SV_STATUS_UP,
		SUPERVISE_SV_STATUS_DOWN,
		SUPERVISE_SV_STATUS_STOPPING,
		SUPERVISE_SV_STATUS_STARTING
	}
	status;

	enum supervise_sv_type {
		SUPERVISE_SV_TYPE_ONESHOT,
		SUPERVISE_SV_TYPE_PIDFILE,
		SUPERVISE_SV_TYPE_SUPERVISED
	}
	type;

	int		shot_done;	// for TYPE_ONESHOT
	FILE	*pidfile;	// for TYPE_PIDFILE

	pid_t	process;
	time_t	started;

	// padding
	char	_[16];
};

struct supervise_sv *supervise_sv_new(void);
void supervise_sv_free(struct supervise_sv *);

#endif /* GINITD_SUPERVISE_SV_H */
