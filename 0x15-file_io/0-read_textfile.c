#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it
 * to the POSIX standard output.
 * @filename: The name of the file to be read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *file;
	char *buffer;
	ssize_t bytesRead, bytesWritten;

	if (filename == NULL)
		return (0);

	file = fopen(filename, "r");

	if (file == NULL)
		return (0);

	buffer = malloc((letters + 1) * sizeof(char));

	if (buffer == NULL)
	{
		fclose(file);
		return (0);
	}

	bytesRead = fread(buffer, sizeof(char), letters, file);

	if (bytesRead <= 0)
	{
		fclose(file);
		free(buffer);
		return (0);
	}

	bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);
	if (bytesWritten != bytesRead)
	{
		fclose(file);
		free(buffer);
		return (0);
	}

	fclose(file);
	free(buffer);
	return (bytesRead);
}
