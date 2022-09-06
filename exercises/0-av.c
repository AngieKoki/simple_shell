#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints all arguments in argvector without using ac
 * @argc: the number of args passed
 * @argv: the argument list passed
 * Return: 0 when succesful
 */
int main (int __attribute__((unused)) argc, char *argv[])
{
	int i;
	
	for (i = 1; argv[i] != NULL; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
