#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - prints the PID of the parent process
 * Return: 0 when succesful
 */
int main(void)
{
	pid_t p_pid;
	p_pid = getppid();
	printf("%d\n", p_pid);
	return (0);
}
