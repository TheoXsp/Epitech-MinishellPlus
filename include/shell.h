/*
** EPITECH PROJECT, 2021
** shell headers
** File description:
** shell
*/

#ifndef SHELL_H_
#define SHELL_H_

// Defines
#define T_NORMAL 0
#define T_DELIM 1
#define T_GET 2
#define T_SEPARATOR 3
#define ID_WITHOUT -1
#define ID_SPACE 0
#define ID_TAB 1
#define ID_DOUBLE_QUOTE 2
#define ID_SIMPLE_QUOTE 3
#define ID_BACK_QUOTE 4
#define ID_PARENTHESE 5
#define ID_REDIRECTION 6
#define ID_DOUBLE_RIGHT 7
#define ID_RIGHT 8
#define ID_DOUBLE_LEFT 9
#define ID_LEFT 10
#define ID_OR 11
#define ID_AND 12
#define ID_SEP 13
#define ID_PIPE 14
#define ID_BACKGROUND 15

// Includes
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

// Structs
typedef struct var {
    char *key;
    char *value;
} var_t;

typedef struct list {
    var_t *data;
    struct list *next;
} list_t;

typedef struct config {
    char *hostname;
    char *currpath;
} config_t;

typedef struct flag_s {
    char *flag;
    int (*redirect)(list_t **env, char **args);
} flags_t;

typedef struct arg {
    char *token;
    short TYPE;
    short ID;
} arg_t;

typedef struct token {
    char *token;
    char *end;
    short TYPE;
    short ID;
} token_t;

typedef struct argslist {
    arg_t *data;
    struct argslist *next;
} argslist_t;

// Cleaning funcs
void unalloc_tab(char **tab);
void clear_node(list_t *node);
void free_confs(config_t *confs);

// LL funcs
void list_push(list_t **head, var_t *data);
void list_stack(list_t **head, var_t *data);
void list_destroy(list_t *head);
void list_remove(list_t **head, int index);
void list_remove_from_key(list_t **head, char *key);

// Utils funcs
char *copy_from_to(char *str, char start, char delim);
int get_list_size(list_t *list);
char **str_to_arr(char *str, char delim);
int get_args_nbr(char **args);
char **alloc_arg_tab(char *str, int size, char delim);
int set_quote_str(char **res, char *str, int *i, int d);

// Env funcs
void init_env(list_t **listenv, char **env);
char **env_to_tab(list_t *lenv);
char *get_env_value(list_t *lenv, char *key);
void update_env_value(list_t *lenv, char *key, char *value);
void env_add(list_t **lenv, char *key, char *value);

// Input handling funcs
flags_t *init_flags(void);
char *clean_str(char *str);
char *get_input(list_t *lenv, config_t *confs);
int get_cmd(list_t **lenv, flags_t *flags, char **args);

// Builtins
int my_cd(list_t **env, char **args);
int my_exit(list_t **env, char **args);
int my_setenv(list_t **env, char **args);
int my_unsetenv(list_t **env, char **args);
int my_env(list_t **env, char **args);

// Builtins error checking
int cd_err_check(list_t *lenv, char **args);
int check_cd_minus(list_t *lenv, char **args, int size);
int skip_quotes(char *str, int *i);

// Execs
int run(list_t *lenv, char **args, char *path);
int resolve_cmd(list_t *lenv, char **args);
int resolve_path(list_t *lenv, char **args);
int get_status(int status);
bool can_access(char *path);
bool does_exist(char *path);
void string_assembly(char *str, char *path, char *piece);
char *reset_string(char *str);
bool can_it_run(char *path);

// Special execes
int run_redirect(list_t *lenv, char **args, char **sargs, bool append);
int get_redirect_cmd(list_t **lenv, char **args, char **sargs, bool append);

// Flex configs for prompt
config_t *init_confs(list_t *lenv);
char *update_confs(list_t *lenv, config_t *confs);

// Parser funcs
arg_t *is_delim(char *str, int *i);
void set_string(arg_t *arg, char *str, int *i);
int set_delim_str(arg_t *arg, char *str, int *i, char delim);
arg_t *init_temp_arg(char c);
void clear_temp_arg(arg_t *temp);
argslist_t *parser(char *str);
char **get_args_tab(argslist_t *list);
argslist_t *parser(char *str);
bool check_validity(argslist_t *args);
int exec_loop(list_t **lenv, char *buffer, flags_t *flags);
argslist_t *get_next_args(argslist_t *list, argslist_t **temp);

// LL parsing func
void listarg_stack(argslist_t **head, arg_t *data);
void listarg_destroy(argslist_t *head);

#endif /* !SHELL_H_ */