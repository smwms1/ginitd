#include <stdio.h>

#include "logging.h"
#include "supervise_sv.h"
#include "supervise_sv_status.h"
#include "supervise_sv_status_getpath.h"

int supervise_sv_update_status(struct supervise_sv *self) {
	int i;
	char *status_str;

	// Clean the file.
	if (self->status_fp)
		fclose(self->status_fp);

	self->status_fp = fopen(supervise_sv_status_getpath(self), "w");

	if (!self->status_fp) {
		glogerr("could not open status file");
		return -1;
	}

	// We'll assume that the status file is already open.
	switch (self->status) {
		case SUPERVISE_SV_STATUS_UP:
			status_str	= "up";
			break;

		case SUPERVISE_SV_STATUS_DOWN:
			status_str	= "down";
			break;

		case SUPERVISE_SV_STATUS_STOPPING:
			status_str	= "stopping";
			break;

		case SUPERVISE_SV_STATUS_STARTING:
			status_str	= "starting";
			break;
	}

	if (self->status == SUPERVISE_SV_STATUS_DOWN)
		fprintf(
			self->status_fp,
			"STATUS=down\n"
		);
	else
		switch (self->type) {
			case SUPERVISE_SV_TYPE_ONESHOT:
				fprintf(
					self->status_fp,
					"STATUS=%s\nSTARTED=%ld\n",
					status_str,
					self->started
				);
				break;

			case SUPERVISE_SV_TYPE_PIDFILE:
			case SUPERVISE_SV_TYPE_SUPERVISED:
				fprintf(
					self->status_fp,
					"STATUS=%s\nSTARTED=%ld\nPID=%d\n",
					status_str,
					self->started,
					self->process
				);
		}

	return 0;
}
