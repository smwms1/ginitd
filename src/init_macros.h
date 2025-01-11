#ifndef GINITD_INIT_MACROS_H
#define GINITD_INIT_MACROS_H

#define INIT_PID1_PIPE		"/run/init/pid1.pipe"
#define INIT_RUNLEVEL_STAT	"/run/init/runlevel"
#define INIT_RC_RUNLEVEL_SC	"/sbin/runlevel-start"
#define INIT_MAINLOOP_WAIT	1

#define INIT_USAGE											\
	"usage: \033[1minit\033[0m \033[90m[-h]\033[0m "		\
	"[0136Ss]\n"

#define INIT_USAGE_EXTENDED									\
	"\033[1;36marguments:\033[0m\n"							\
	"  \033[1m0\033[0m"										\
	"       "												\
	"Shut down the computer.\n"								\
	"  \033[1m1, S, s\033[0m"								\
	" "														\
	"Change to single-user mode.\n"							\
	"  \033[1m3\033[0m"										\
	"       "												\
	"Change (from single-user mode) to normal operation.\n"	\
	"  \033[1m6\033[0m"										\
	"       "												\
	"Reboot the computer.\n"								\
	"\n"													\
	"\033[1;36moptions:\033[0m\n"							\
	"  \033[1m-h\033[0m"									\
	"      "												\
	"Display this help message.\n"							\
	"\n"													\
	"init is a part of ginitd:\n"							\
	"Copyright (C) 2019-2025 Solomon Wood\n"

#define INIT_EPERM_ERROR										\
	"\033[31mShould you have run this as superuser?\033[0m\n"

#define INIT_EHOSTDOWN_ERROR										\
	"\033[31m"														\
	"The system has been booted without ginitd as the active init "	\
	"system (PID 1)."												\
	"\n"															\
	"Cannot operate."												\
	"\033[0m\n"

#endif
