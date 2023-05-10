#ifndef _SHELL_H_
#define _SHELL_H_

/* alx alx  Methode */

#include <string.h>
#include <sys/types.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>


/* this is for Command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* For Convert_number(_) */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* For Read or for write buffers */
#define BUF_FLUSH -1
#define WRITE_BUF_SIZE 1024
#define READ_BUF_SIZE 1024


/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	 4096

extern char **environ;


/**
 *  alx group project
 * structure list_str - singly linked list
 * @num: the number field.
 * @str: a string.
 * @next: this points to the next node.
 */
typedef struct liststr
{
	int num;char *str;
	struct liststr *next;
} list_t;

/**
 *structure passinformation - that contains pseudo-arguments to pass into a function,
 *		allowing the uniform prototype forn the function pointer structure
 *@arg: a string that was generated from getline that contains arguements
 *@argv: an array of strings generated from argument
 *@path: a string path for a current cmd
 *@argc: the argument count
 *@line_count: error count
 *@err_num: error code for exit(_)s
 *@linecount_flag: if it is on count this line of input
 *@fname: Program filename
 *@env: the linked list local copy of environment
 *@environ: custom modified copy of environment from LL environ
 *@history: history node
 *@alias:  alias node
 *@env_changed:  make it on if environ was changed
 *@status: the return status of the last executable'd cmd
 *@cmd_buf: address of pointer to command_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, semicolon
 *@readfd: the fd that is from to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf; /* pointer to command ; chain buffer, for memory management */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *structure builtin -- that contains a builtin str and related function
 *@type: the builtin cmd flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* Toemshloop.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* toemparser.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* looph_sh.c */
int loophsh(char **);

/* toem_errors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* toem_string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* toem_string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* toem_exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* toem_tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* toem_realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* toem_memory.c */
int bfree(void **);

/* toem_atoi.c */
int _isalpha(int);
int _atoi(char *);
int interactive(info_t *);
int is_delim(char, char *);


/* toem_builtin.c */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* toem_builtin1.c */
int _myhistory(info_t *);
int _myalias(info_t *);


/* toem_errors1.c */
char *convert_number(long int, int, int);
void remove_comments(char *);
int print_d(int, int);
int _erratoi(char *);
void print_error(info_t *, char *);

/*toem_getline.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* toem_getinfo.c */
void free_info(info_t *, int);
void set_info(info_t *, char **);
void clear_info(info_t *);

/* toem_environ.c */
int _myunsetenv(info_t *);
int populate_env_list(info_t *);
int _mysetenv(info_t *);
char *_getenv(info_t *, const char *);
int _myenv(info_t *);

/* toem_getenv.c */
int _setenv(info_t *, char *, char *);
int _unsetenv(info_t *, char *);
char **get_environ(info_t *);

/* toem_history.c */
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);
int read_history(info_t *info);
char *get_history_file(info_t *info);
int write_history(info_t *info);

/* toem_lists.c */
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);
size_t print_list_str(const list_t *);
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);

/* toem_lists1.c */
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);
size_t list_len(const list_t *);
size_t list_len(const list_t *);
char **list_to_strings(list_t *);

/* toem_vars.c */
int replace_vars(info_t *);
int replace_string(char **, char *);
int replace_alias(info_t *);
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);

/* alx 2023 to  alx 2024 */


#endif
