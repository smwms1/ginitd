#ifndef OPUS_RUNLEVEL_MACROS_H
#define OPUS_RUNLEVEL_MACROS_H

#define RUNLEVEL_BUFSIZE	32

#define RUNLEVEL_USAGE										\
	"usage: \033[1mrunlevel\033[0m \033[90m[-rh]\033[0m\n"	\

#define RUNLEVEL_USAGE_EXTENDED								\
	"\033[1;36moptions:\033[0m\n"							\
	"  \033[1m-r\033[0m"									\
	"      "												\
	"Display the status information in raw format.\n"		\
	"  \033[1m-h\033[0m"									\
	"      "												\
	"Display this help message.\n"							\
	"\n"													\
	"runlevel is a part of opus:\n"						\
	"Copyright (C) 2019-2025 Solomon Wood\n"

#endif /* OPUS_RUNLEVEL_MACROS_H */
