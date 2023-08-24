#include "monty.h"

/**
 * open_file - opens the file
 * @filename: the file to be opened
 */

void open_file(char *filename)
{
	int  fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		open_failed(filename);
	}

	arguement->stream = fdopen(fd, "r");
	if (arguement->stream == NULL)
	{
		close(fd);
		open_failed(filename);
	}
}

/**
 * open_failed - failed to open file
 * @filename: file
 */

void open_failed(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	free_arg();
	exit(EXIT_FAILURE);
}

/**
 * stream_closed - closes stream or file
 */

void stream_closed(void)
{
	if (arguement->stream == NULL)
		return;
	fclose(arguement->stream);
	arguement->stream = NULL;
}
