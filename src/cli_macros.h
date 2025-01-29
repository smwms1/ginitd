#ifndef OPUS_CLI_MACROS_H
#define OPUS_CLI_MACROS_H

#include "cli_args.h"

// Call this at the beginning of every main() function.
#define CLI_ARGS_SETUP()				\
	cli_argc	= argc;					\
	cli_argv	= argv;

#endif /* OPUS_CLI_MACROS_H */
