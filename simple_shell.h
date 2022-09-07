#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <limits.h>
#define BUFF_SIZE 300
/**
 * struct link - node that contains the directories
 * @dir: directory
 * @next: position to change the node
 */
typedef struct link
{char *dir;
struct link *next;
} link_t;
/**
* struct formats - struct formats
* @ch: pointer to firts element.
* @func: The function associated.
*/
typedef struct formats
	{
		char *ch;
		int (*func)();
	} form;

char *execute_command(char *argm);
int _putchar(char c);
int _printf(const char *format, ...);
int p_aux_int(long int n, long int);
int print_str(va_list arguments);
int print_char(va_list arguments);
int print_int(va_list arguments);
extern char **environ;
char *_getenv(const char *name);
char *_strcpy(char *dest, char *src);
char *_strtok(char *str, char *delim);
ssize_t _getline(char **buff, size_t *size, FILE *stream);
char **splitline(char *cmd_line);
void signal_c(int sign);
int _myexit(char *line);
int _strlen(char *s);
int execute(char **arg, char **argv, int counter);
link_t *_add_nodeint_end(link_t **head, char *n);
size_t _print_listint(link_t *h);
link_t *_link(char *a);
char *_strcat(char *directory, char *slash, char *arg);
char *_which(link_t **head, char *av);
void free_list(link_t *head);
char *check_path(char *argm);
int _myenv(char *line, int counter, char **argv, char **env);
int _getchar(void);
#endif
