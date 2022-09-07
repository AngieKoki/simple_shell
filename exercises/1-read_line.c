#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
/**
 * main - waits for user input and prints it on the screen
 * Return: 0 when succesful
 */
int main(void)
{
	char *buff;
	size_t buffer_size = 100;
	int character_size, write_fd;

	buff = malloc(buffer_size * sizeof(char));
	if (!buff)
	{
		free(buff);
		perror("Unable to allocate mem to buffer");
		exit(98);
	}
	printf("$ ");
	character_size = _getline(&buff, &buffer_size, stdin);
	if (character_size == -1)
	{
		perror("Unable to read your input");
		exit(99);
	}
	write_fd = write(STDOUT_FILENO, buff, character_size);
	if (write_fd == -1)
	{
		perror("Unable to write to the std");
		exit(100);
	}
	return (0);

}
