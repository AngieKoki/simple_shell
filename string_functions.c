#include "simple_shell.h"

/**
 * _strtok - breaks a string into a sequence
 * @str: string
 * @c: specific character to break the string
 * Return: Pointer to divided string or NULL if fails
 */

char *_strtok(char *str, char *c)
{
	int i = 0;
	int j = 0;
	int a = 0;
	static char *track;

	if (!c || (!str && !track))
		return (NULL);
	str == NULL ? str = track : str;
	for (; str[j] == ' ' ; j++)
	{
		if (str[j + 1] == '\0')
			return (NULL);
	}
	for (; str[i] != '\0' ; i++)
		if (str[i] != c[0])
			break;
		else if (str[i + 1] == '\0')
		{
			a = 0, str[i] = '\0';
			break;
		}
		else
			str[i] = '\0';

	if (a == 0)
	{
		track = NULL;
		return (str + j);
	}
	if (str + i)
		track = str + i;
	else
		track = NULL;
	return (str + j);
}

/**
 * _strlen - finds the length of a string
 * @s: string input
 * Return: number of bytes of the string
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		continue;
	}
	return (i);
}

/**
 * _strcpy - copies source to destination
 * @src: source
 * @dest: destination
 * Return: copy of the character
 */

char *_strcpy(char *src, char *dest)
{
	int i;

	i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - Concatenate two directories with the array[0]
 * @directory: directories
 * @slash: /
 * @arg: array of commands
 * Return: str
 */

char *_strcat(char *directory, char *slash, char *arg)
{
	char *str = NULL;
	int l1, l2, i, k;

	l1 = _strlen(directory);
	l2 = _strlen(arg);
	str = malloc(sizeof(char) * (l1 + l2 + 2));
	if (!str)
		return (NULL);

	for (i = 0; directory[i]; i++)
		str[i] = directory[i];
	str[i] = *slash;
	k = i + 1;

	for (i = 0; arg[i]; i++)
		str[k + i] = arg[i];
	str[k + i] = '\0';

	return (str);
}
