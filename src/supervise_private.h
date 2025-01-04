#ifndef GINITD_SUPERVISE_PRIVATE_H
#define GINITD_SUPERVISE_PRIVATE_H

#include <limits.h>

// These are passed in via the command line.
extern char	services_path[PATH_MAX];
extern char	tempdir_path[PATH_MAX];

// These are generated, and cached.
extern char status_path[PATH_MAX];


// The control pipe
extern int	control;

#endif /* GINITD_SUPERVISE_PRIVATE_H */
