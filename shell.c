#include "simple_shell.h"

/**
 * main - the entry point to the program
 * @argc: the argument counter
 * @argv: the argument vector containing commands passed in
 * @env: environment variable
 * Return: 0 when successful
 */
int main(int __attribute__((unused))argc, char *argv[], char **env)
{
	int status_output = 0, status = 1, counter = 0;

	while (status)
	{
		char *command_line = NULL, **arg = NULL;
		size_t line_size = 0;

		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "#cisfun$ ", 10);
		signal(SIGINT, signal_c);
		status = getline(&command_line, &line_size, stdin);
		if (status < 0)
		{
			free(command_line);
			exit(status_output);
		}
		if (status == 1)
		{
			free(command_line);
			continue;
		}
		if (status != EOF)
		{
			counter++;
			_strtok(command_line, "\n");
			if (_myexit(command_line) == 0)
				return (status_output);
			if (_myenv(command_line, counter, argv, env) == 0)
				continue;
			arg = splitline(command_line);
			if (arg[0] == NULL)
			{
				free(command_line), free(arg);
				continue;
			}
			status_output = execute(arg, argv, counter);
		}
		free(command_line), free(arg);
	}
	return (status_output);
}
