#include "simple_shell.h"
#include <errno.h>

/**
 * _getenv - finds the environment variable name
 * @env_name: the variable name
 * Return: Pointer to the environment variable and Null if fails
 */
char *_getenv(const char *env_name)
{
	int i, j;
	char *a, *cp;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; env_name[j] == environ[i][j] && env_name[j] != '\0'; j++)
		{
			if (env_name[j + 1] == '\0')
			{
				a = &environ[i][j + 2];
				cp = malloc(sizeof(char) * _strlen(a) + 1);

				if (!cp)
				{
					free(NULL);
					return (NULL);
				}
				_strcpy(cp, a);
				return (cp);
			}
		}
	}
	return (NULL);
}
/**
 * _getchar - gets the number of characters from the STDIN
 *
 * Return: nothing
 */

int _getchar(void)
{
	static unsigned char buff[BUFF_SIZE];
	static int index;
	static int count;

	index = 0;
	count = 0;
	if (index >= count)
	{
		index = 0;
		count = read(STDIN_FILENO, buff, BUFF_SIZE);
		printf("%i\n", count);
		if (count == 0)
			return (EOF);
		if (count < 0)
			return (EOF);
	}
	return (buff[index++]);
}

/**
 * _getline - gets the input line from the prompt
 * @buff: command buffer line
 * @size: size of the command buffer line
 * @stream: file stream
 * Return: number of bytes from the command line input
 */

ssize_t _getline(char **buff, size_t *size, FILE *stream)
{
	size_t count = 0;
	size_t b_size = 1024;
	char c;

	if (!buff || !size || !stream)
		return (-1);
	if (*buff == NULL)
	{
		*buff = malloc(b_size);
		if (!(*buff))
			return (-1);
	}
	while ((c = _getchar()) != EOF)
	{
		if (c == '\n')
		{
			count++;
			break;
		}
		count++;
		*buff[count - 1] = c;
	}
	if (c == EOF)
		return (-1);
	*buff[count] = '\0';
	return (count);

}

/**
 * splitline - splits lines from the command line input
 * @cmd_line: command line input string
 * Return: a pointer to the array of splitted strings
 */

char **splitline(char *cmd_line)
{
	char **str;
	int size = 100, pos = 0;
	char *word;

	str = malloc(sizeof(char *) * size);
	if (!str)
		exit(EXIT_FAILURE);
	word = _strtok(cmd_line, " ");
	while (word != NULL)
	{
		str[pos++] = word;
		word = _strtok(NULL, " ");
	}
	str[pos] = NULL;
	return (str);
}

/**
 * execute - executes the process
 * @arg: args from the command line
 * @argv: a list of arg strings
 * @counter: number of execution processes
 * Return: the status output
 */

int execute(char **arg, char **argv, int counter)
{
	pid_t child_process;
	int status, status_output = 0;
	char *buff = NULL, *command_path = NULL;

	command_path = check_path(arg[0]);
	if (command_path == NULL)
	{
		buff = execute_command(arg[0]);
		if (!buff)
		{
			_printf(" %s: %d: %s: not found\n", argv[0], counter, arg[0]);
			free(buff);
			return (1);
		}
	}
	child_process = fork();
	if (child_process < 0)
		exit(errno);
	else if (child_process == 0)
	{
		if (command_path != NULL)
		{
			if (execve(command_path, arg, environ) == -1)
				exit(errno);
		}
		if (execve(buff, arg, environ) == -1)
			exit(errno);
	}
	wait(&status);
	if (WIFEXITED(status))
		status_output = WEXITSTATUS(status);
	free(buff);
	return (status_output);
}
