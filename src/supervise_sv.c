#include <stdlib.h>

#include "supervise_sv.h"

struct supervise_sv *supervise_sv_new(void) {
	struct supervise_sv *self;

	self = malloc(sizeof(struct supervise_sv));

	// Set defaults
	self->path[0]	= '\0';
	self->status_fp	= NULL;
	self->status	= SUPERVISE_SV_STATUS_DOWN;
	self->type		= SUPERVISE_SV_TYPE_SUPERVISED;
	self->shot_done	= 0;
	self->pidfile	= NULL;
	self->process	= 0;
	self->started	= 0;
	
	return self;
}

void supervise_sv_free(struct supervise_sv *self) {
	free(self);
}
