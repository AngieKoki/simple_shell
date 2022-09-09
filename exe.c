#include "main.h"

/**
 * handle_builtin - Handle Builtin Command
 * @cmd: Parsed Command
 * @er:statue of last Excute
 * Return: -1 Fail 0 Succes (Return :Excute Builtin)
 */

int handle_builtin(char **cmd, int er)
{
	 bul_t b[] = {
		{"cd", cd_},
		{"env", dis_env},
		{"help", dis_help},
		{"echo", echo_func},
		{"history", dis_hist},
		{NULL, NULL}
	};
	int i = 0;

	while ((b + i)->command)
	{
		if (_strcmp(cmd[0], (b + i)->command) == 0)
		{
			return ((b + i)->find(cmd, er));
		}
		i++;
	}
	return (-1);
}
/**
 * check_cmd - Excute Simple Shell Command (Fork,Wait,Excute)
 *
 * @cmd:Parsed Command
 * @input: User Input
 * @c:Shell Excution Time Case of Command Not Found
 * @argv:Program Name
 * Return: 1 Case Command Null -1 Wrong Command 0 Command Excuted
 */
int check_cmd(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			path_cmd(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
/**
 * signal_handle - Handle ^C
 * @sig:Captured Signal
 * Return: Void
 */
void signal_handle(int sig)
{
	if (sig == SIGINT)
	{
		PRINT("\n;) ");
	}
}
