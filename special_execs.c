/*
** EPITECH PROJECT, 2021
** special execs funcs
** File description:
** special_execs
*/

#include "my.h"
#include "shell.h"

int run_redirect(list_t *lenv, char **args, char **sargs, bool append)
{
    int status = 0;
    char **env = env_to_tab(lenv);

    if (fork() != 0) {
        wait(&status), status = get_status(status);
        unalloc_tab(env);
        return status;
    }
    else {
        int fd = 0;

        if (append == false)
            fd = open(sargs[0], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
        else
            fd = open(sargs[0], O_RDWR | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
        dup2(fd, 1);
        dup2(fd, 2);
        close(fd);
        if (execve(args[0], args, env) == -1)
            exit(127);
    }
}