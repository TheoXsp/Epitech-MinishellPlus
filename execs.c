/*
** EPITECH PROJECT, 2021
** execution funcs for shell
** File description:
** execs
*/

#include "my.h"
#include "shell.h"

int get_status(int status)
{
    if (WIFEXITED(status))
        return WEXITSTATUS(status);
    if (WIFSIGNALED(status)) {
        my_printf("%s", strsignal(WTERMSIG(status)));
        if (WCOREDUMP(status))
            my_printf(" (core dumped)");
        my_printf("\n");
        return 139;
    }
}

static int get_last_char_index(char *str, char c)
{
    int i = 0;
    int index = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            index = i;

    }
    return index;
}

static char *update_binary_name(char *str)
{
    int d = 0;
    int temp = 0;
    char *buffer = NULL;
    int size = 0;

    temp = get_last_char_index(str, '/') + 1;
    if (temp == 1)
        return str;
    for (int i = temp; str[i] != '\0'; i++, size++);
    buffer = malloc(sizeof(char) * (size + 1));
    for (d = 0; str[temp] != '\0'; temp++, d++)
        buffer[d] = str[temp];
    buffer[d] = '\0';
    free(str);
    return buffer;
}

int run(list_t *lenv, char **args, char *path)
{
    int status = 0;
    char **env = env_to_tab(lenv);

    if (fork() != 0) {
        wait(&status);
        status = get_status(status);
        unalloc_tab(env);
        return status;
    }
    else if (execve(path, args, env) == -1)
        exit(127);
}