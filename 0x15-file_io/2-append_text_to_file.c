#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The text content to append (NULL-terminated string).
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, bytesWritten, textLength;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		close(fd);
		return (1);
	}

	for (textLength = 0; text_content[textLength] != '\0'; textLength++)
		;

	bytesWritten = write(fd, text_content, textLength);
	close(fd);

	if (bytesWritten == -1 || bytesWritten != textLength)
		return (-1);

	return (1);
}
