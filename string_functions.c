#include "main.h"

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
 * _strcat - Concatenate two strings
 * @src: first string
 * @dest: second string
 * Return: first and second string
 */

char *_strcat(char *src, char *dest)
{
	char *s = src;

	while (*src != '\0')
	{
		src++;
	}
	while (*dest != '\0')
	{
		*src = *dest;
		src++;
		dest++;
	}
	*src = '\0';
	return (s);
}
