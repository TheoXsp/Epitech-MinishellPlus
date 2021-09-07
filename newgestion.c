/*
** EPITECH PROJECT, 2021
** new gestion management with tokens
** File description:
** newgestion
*/

#include "my.h"
#include "shell.h"

static int clean_exit(argslist_t *list, int status)
{
    listarg_destroy(list);
    return status;
}

bool do_exec(argslist_t *list)
{
    if (list == NULL)
        return true;
    if (list->data->TYPE != T_GET)
        return true;
    return false;
}

int special_exec(list_t **lenv, argslist_t **list, argslist_t *args)
{
    argslist_t *temp = NULL;
    int type = -1;

    type = (*list)->data->ID;
    (*list) = (*list)->next;
    (*list) = get_next_args(*list, &temp);
    if (type == ID_RIGHT)
        get_redirect_cmd(lenv, get_args_tab(args), get_args_tab(temp), false);
    if (type == ID_DOUBLE_RIGHT)
        get_redirect_cmd(lenv, get_args_tab(args), get_args_tab(temp), true);
}

argslist_t *get_next_args(argslist_t *list, argslist_t **temp)
{
    while (list != NULL) {
        if (list->data->TYPE != ID_WITHOUT)
            break;
        listarg_stack(temp, list->data);
        list = list->next;
    }
    return list;
}

int exec_loop(list_t **lenv, char *buffer, flags_t *flags)
{
    int s = 0;
    argslist_t *list = NULL;
    argslist_t *temp = NULL;
    char **args = NULL;

    if ((list = parser(buffer)) == NULL)
        return 0;
    if (check_validity(list) == false)
        return clean_exit(list, 1);
    while (list != NULL) {
        if (list->data->TYPE == T_SEPARATOR) {
            list = list->next;
            continue;
        }
        if (list->data->TYPE == ID_WITHOUT) list = get_next_args(list, &temp);
        if (do_exec(list) == true) s = get_cmd(lenv, flags, get_args_tab(temp));
        else if (list->data->TYPE == T_GET)
            s = special_exec(lenv, &list, temp);
        listarg_destroy(temp), temp = NULL;
    }
    return s;
}