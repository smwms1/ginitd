#include <string.h>

#include "path_private.h"

char *path_concat(char *path1, char *path2) {
	strcpy(path_buf, path1);
	strcat(path_buf, "/");
	strcat(path_buf, path2);

	return path_buf;
}
