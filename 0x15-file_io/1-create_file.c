#include "main.h"
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * create_file - Creates a file with the specified filename and
 * write the provided text content into it.
 * @filename: The name of the file to create.
 * @text_content: The text content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, bytesWritten, textLength;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (text_content == NULL)
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
