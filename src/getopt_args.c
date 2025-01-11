#include <getopt.h>

#include "cli_args.h"
#include "getopt_args.h"

int getopt_args_remaining(void)	{ return cli_argc - optind;	}
int getopt_args_starts_at(void)	{ return optind;			}
