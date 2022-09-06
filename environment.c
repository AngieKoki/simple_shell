#include "simple_shell.h"

/**
 * check_path - checks if the arg is a path
 * @arg: entry to the argument variables
 * Return: arg if found and null if not found
 */
char *check_path(char *arg)
{
	if (access(arg, F_OK && X_OK) == 0)
		return (arg);
	return (NULL);
}

/**
 * _getenv - find the env variable name
 * @name: variable name
 * Return: NULL if fails or pointer to value of env.var.
 */
char *_getenv(const char *name)
{
	int i;
	int j;
	char *a;
	char *copy;

	for (i = 0 ; environ[i] != NULL ; i++)
	{
		for (j = 0 ; name[j] == environ[i][j] && name[j] != '\0' ; j++)
		{
			if (name[j + 1] == '\0')
			{
				a = &environ[i][j + 2];
				copy = malloc(sizeof(char) * _strlen(a) + 1);

				if (!copy)
					return (NULL);

				copy = _strcpy(copy, a);
				return (copy);
			}
		}
	}
	return (NULL);
}
