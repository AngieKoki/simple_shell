#include "simple_shell.h"

/**
* _putchar - writes the character c to stdout
* @c: character to print
* Return: On success 1, error, -1
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* print_char - writes the character to the stdout.
* @args: character to print
* Return: integer
*/

int print_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}

/**
* print_int - print variable type integer.
* @args: integer arguments
* Return: integer
*/

int print_int(va_list args)
{
	long int n, n_aux, d = 1, l_aux;
	int count = 0;

	n = va_arg(args, int);

	if (n < 0)
	{
		n_aux = -n;
		_putchar('-');
		count++;
	}
	else
		n_aux = n;
	l_aux = n_aux;
	while (n_aux > 9)
	{
		n_aux = n_aux / 10;
		d *= 10;
	}
	while (d > 0)
	{
		_putchar(((l_aux / d) % 10) + '0');
		count++;
		d /= 10;
	}
	return (count);
}

/**
* print_str - print variable type string.
* @args: number of arguments.
* Return: Integer.
*/
int print_str(va_list args)
{
	char *p;
	int a;

	p = va_arg(args, char *);
	if (p == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	for (a = 0 ; p[a] != '\0' ; a++)
	{
	_putchar(p[a]);
	}
	return (a);
}

/**
* _printf - print c,s,f,u,i,d
* @format: arguments
* Return: length of all characters
*/
int _printf(const char *format, ...)
{
form types[] = {
	{"c", print_char}, {"s", print_str};
	{"d", print_int}, {"i", print_int}, {NULL, NULL}};
	va_list arguments;
	int pos = 0, length = 0, pos_form;

	va_start(arguments, format);
	if (!format || !format[pos])
		return (-1);
	for (; format[pos]; pos++)
	{
		if (format[pos] == '%')
		{
			if (format[pos + 1] == '\0')
				return (-1);
			if (format[pos + 1] == '%')
				_putchar(37), length++;
			else
			{
				for (pos_form = 0; types[pos_form].ch != NULL; pos_form++)
				{
					if (types[pos_form].ch[0] == format[pos + 1])
					{
						length += types[pos_form].func(arguments);
						break;
					}
				}
				if (types[pos_form].ch == NULL)
				{
					_putchar(format[pos]);
					_putchar(format[pos + 1]), length += 2;
				}
			}
			pos++;
		}
		else
			_putchar(format[pos]), length++;
	}
	va_end(arguments);
	return  (length);
}
