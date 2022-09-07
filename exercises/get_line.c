#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * _getline - custom implementation of builtin getline function
 * @lineptr: the pointer to the buffer for storing the line
 * @len: size of buffer storage for the line
 * @stream: input stream of characters
 * Return: return the number of characters read, including the delimiter
 *character, but not including the terminating null byte ('\0').
 *In the event of a failure, errno is set to indicate the error.
 */
ssize_t _getline(char **lineptr, size_t *len, FILE *stream)
{
	/* buffer array of 128 bytes as param for fgets */
	char buff[128];

	/* check if function was called with correct args */
	if (lineptr == NULL || len == NULL)
	{
		perror("Error! Bad arguments\n");
		return (-1);
	}
	/* check if the file pointer exists */
	if (stream == NULL)
	{
		perror("Error! Bad stream pointer");
		return (-1);
	}
	if (*lineptr == NULL)
	{
		*len = sizeof(buff);
		if ((*lineptr = malloc(*len)) == NULL)
		{
			perror("Unable to allocate memory for the line buffer.");
			free(*lineptr);
			return (-1);
		}
	}
	(*lineptr)[0] = '\0';
	while (fgets(buff, sizeof(buff), stream) != NULL)
	{
		/* resizing the line buffer when necessary */
		if (*len - strlen(*lineptr) < sizeof(buff))
		{
			*len *= 2;
			if ((*lineptr = realloc(*lineptr, *len)) == NULL)
			{
				perror("unable to reallocate memory for the buffer.");
				free(*lineptr);
				return (-1);
			}
		}
		/* appending the buff to the end of the line */
		strcat(*lineptr, buff);
		/* checking if the lineptr contains an EOF which is the \n */
		if (*lineptr[strlen(*lineptr) - 1] == '\n')
			return strlen(*lineptr);
	}
	return (-1);
}
