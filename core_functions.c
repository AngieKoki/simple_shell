#include "simple_shell.h"

/**
 * _getenv - finds the environment variable name
 * @name: variable name
 * Return: Pointer to envirnonemnt variable or NULL if fails
 */

char *_getenv(const char *name)
{
	int i, j;
	char *a, *copy;

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; name[j] == env[i][j] && name[j] != '\0'; j++)
		{
			if (name[j + 1] == '\0')
			{
				a = &env[i][j + 2];
				copy = malloc(sizeof(char) * strlen(a) + 1);

				if (!copy)
					return (NULL);

				copy = strcpy(copy, a);
				return (copy);
			}
		}
	}
	return (NULL);
}
