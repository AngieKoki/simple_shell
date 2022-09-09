#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <linux/limits.h>

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINT(c) (write(STDOUT_FILENO, c, _strlen(c)))

extern char **environ;

/*string handlers */
char *_strtok(char *str, const char *tok);
unsigned int _delim(char c, const char *str);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);

int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);

int intlen(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);

int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);

/* Mem.c */
void free_env(char **env);
void *fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **input, char *line);


/*Input */
void prompt(void);
void signal_handle(int sig);
char *_getline(void);

/* Env Functions */
void hashtag_(char *buff);
int history(char *input);
int dis_hist(char **cmd, int er);
int dis_env(char **cmd, int er);
int cd_(char **cmd, int er);
int dis_help(char **cmd, int er);
int echo_func(char **cmd, int er);
void exit_shell(char **cmd, char *input, char **argv, int c);
int print_echo(char **cmd);

/* errors */
void print_number(unsigned int n);
void print_number_in(int n);
void print_error(char *line, int c, char **argv);
void _prerror(char **argv, int c, char **cmd);

/* commands */
int path_cmd(char **line);
char *_getenv(char *name);
char **parse_cmd(char *cmd);
int handle_builtin(char **cmd, int er);
void read_file(char *filename, char **argv);
char *build(char *token, char *value);
int check_builtin(char **cmd);
void creat_env(char **envi);
int check_cmd(char **tokens, char *line, int count, char **argv);
void treat_file(char *line, int counter, FILE *fd, char **argv);
void exit_file(char **cmd, char *line, FILE *fd);


/**
 * struct bulltin - contain bultin to handle and function to excute
 * @command:pointer to char
 * @find:function to excute when bultin true
 */
typedef struct builtin
{
  char *command;
  int (*find)(char **line, int er);
}bul_t;

#endif
