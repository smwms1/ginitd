/*
	Copyright (C) 2019-2025 Solomon Morgan Wood
*/

#ifdef HAVE_SELINUX

#include <selinux/selinux.h>

void init_handle_selinux(char *argv_0) {
	if (getenv("SELINUX_INIT") == NULL) {
		if (is_selinux_enabled() != 1) {
			if (selinux_init_load_policy(&enforce) == 0) {
				setenv("SELINUX_INIT", "YES", 1);
				execl(argv_0, NULL);
			} else {
				if (enforce > 0) {
					eputs("init: unable to load SELinux policy.\n");
					exit(1);
				}
			}
		}
	}
}

#else

void init_handle_selinux(char *argv_0) {
	// Do nothing
}

#endif
