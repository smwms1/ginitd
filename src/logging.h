#ifndef OPUS_LOGGING_H
#define OPUS_LOGGING_H

/*
	NOTE:
	  This is an 'all-in-one' header file. As logging will be used by all
	  programs and subsystems, and all will need exactly the same functions, I
	  have decided to make this all-in-one header file for ease-of-use. I do
	  not intend to do this for other subsystems.
*/

#include "logging_errno.h"	// IWYU pragma: export
#include "logging_init.h"	// IWYU pragma: export
#include "logging_logf.h"	// IWYU pragma: export

#endif /* OPUS_LOGGING_H */
