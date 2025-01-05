#include "path_concat.h"

#include "supervise_private.h"
#include "supervise_sv.h"
#include "supervise_sv_status_getpath.h"

char *supervise_sv_status_getpath(struct supervise_sv *self) {
	char *path;

	path = path_concat(
		supervise_tempdir_path,
		"status"
	);

	path = path_concat(
		path,
		self->path
	);

	return path;
}
