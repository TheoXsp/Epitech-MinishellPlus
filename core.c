/*
** EPITECH PROJECT, 2021
** core funcs for shell
** File description:
** core
*/

#include "my.h"
#include "shell.h"

int main(int ac, char **av, char **env)
{
    list_t *lenv = NULL;
    config_t *confs = NULL;
    char *buffer = NULL;
    flags_t *flags = init_flags();

    init_env(&lenv, env);
    if (isatty(STDIN_FILENO) == 1)
        confs = init_confs(lenv);
    while ((buffer = get_input(lenv, confs)) != NULL) {
        if (buffer[0] != '\n')
            exec_loop(&lenv, buffer, flags);
        free(buffer);
        buffer = NULL;
    }
    list_destroy(lenv);
    free(flags);
    if (isatty(STDIN_FILENO) == 1) {
        my_putstr("exit\n");
        free_confs(confs);
    }
    return 0;
}