/*
** EPITECH PROJECT, 2021
** funcs to handle input for shell
** File description:
** input
*/

#include "my.h"
#include "shell.h"

static int get_arglist_size(argslist_t *list)
{
    int size = 0;
    argslist_t *temp = list;

    for (; temp != NULL; temp = temp->next, size++);
    return size;
}

bool check_validity(argslist_t *args)
{
    argslist_t *lastarg = args;
    argslist_t *temp = args;

    for (int i = 0; temp != NULL; temp = temp->next, i++) {
        if (i != 0) lastarg = lastarg->next;
        if (temp->data->TYPE == ID_WITHOUT)
            continue;
        if (temp->next == NULL && temp->data->TYPE != ID_WITHOUT)
            return false;
        if ((lastarg->data->TYPE != ID_WITHOUT ||
        temp->next->data->ID != ID_WITHOUT) &&
        (temp->data->ID == ID_LEFT || temp->data->ID == ID_DOUBLE_LEFT)) {
            my_printf("Missing name for redirect.\n");
            return false;
        }
        if (temp->data->ID == ID_PIPE &&
        temp->next->data->TYPE != ID_WITHOUT) {
            my_printf("Invalid null command.\n");
            return false;
        }
    }
    return true;
}

char **get_args_tab(argslist_t *list)
{
    int i = 0;
    int d = 0;
    char **args = NULL;
    argslist_t *temp = list;

    if (!list)
        return NULL;
    args = malloc(sizeof(char *) * (get_arglist_size(list) + 1));
    for (i = 0; temp != NULL; i++, temp = temp->next) {
        args[i] = malloc(sizeof(char) * (my_strlen(temp->data->token) + 1));
        for (d = 0; temp->data->token[d] != '\0'; d++)
            args[i][d] = temp->data->token[d];
        args[i][d] = '\0';
    }
    args[i] = NULL;
    return args;
}

char *get_input(list_t *lenv, config_t *confs)
{
    char *buffer = NULL;
    size_t n = 0;

    if (isatty(STDIN_FILENO) == 1)
        confs->currpath = update_confs(lenv, confs);
    if (isatty(STDIN_FILENO) == 1)
        my_printf("\033[4m%s\033[0m:\033[1m%s\033[0m> ",
        confs->hostname, confs->currpath);
    if ((getline(&buffer, &n, stdin)) <= 0) {
        free(buffer);
        return NULL;
    }
    return buffer;
}