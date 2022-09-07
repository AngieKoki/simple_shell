#include "simple_shell.h"

extern char **environ;
/**
 * main - the entry point to the program
 * @argc: the argument counter
 * @argv: the argument vector containing commands passed in
 * Return: 0 when successful
 */
int main(int argc, char *argv[])
{
	int fork_h, status = 1, getline_handler;
	char *inp = NULL;
	size_t inp_size = 0;

	while (status)
	{
	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "#cisfun$ ", 10);
	//signal(SIGINT, signals);
	getline_handler = getline(&inp, &inp_size, stdin);
	if (getline_handler < 0)
		{
			perror("Error! unable to get line");
			free(inp);
			exit(0);
		}
		if (getline_handler == 1)
		{
			free(inp);
			continue;
		}
		if (getline_handler != EOF)
		{
		fork_h = fork();
		if (fork_h == -1)
		{
			perror("Error! cannot fork this process");
			return (-1);
		}
		else if (fork_h == 0)
		{
			printf("I am the child");
			break;
		}
		else
		{
			wait(NULL);
			printf("I am the father");
			break;
		}
	

	}
	return (0);
}
