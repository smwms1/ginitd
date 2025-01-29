#ifndef OPUS_LOGGING_LOGF_H
#define OPUS_LOGGING_LOGF_H

/*
	WARNING:
	  This function has a short name purely to make code that
	  utilises it more readable; I don't want to see a logging_logf
	  every few lines of code. This is AGAINST THE RULES; this is
	  the only instance in which they can be broken.
*/
void glogf(char, char *, ...);

#endif /* OPUS_LOGGING_LOGF_H */
