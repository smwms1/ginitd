#ifndef GINITD_SUPERVISE_PRIVATE_H
#define GINITD_SUPERVISE_PRIVATE_H

#include <limits.h>

// These are passed in via the command line.
extern char	supervise_services_path[PATH_MAX];
extern char	supervise_tempdir_path[PATH_MAX];

// These are generated, and cached.
extern char supervise_status_path[PATH_MAX];


// The control pipe
extern int	supervise_control;

#endif /* GINITD_SUPERVISE_PRIVATE_H */
