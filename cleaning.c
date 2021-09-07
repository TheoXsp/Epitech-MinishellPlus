/*
** EPITECH PROJECT, 2021
** cleaning funcs for shell
** File description:
** cleaning
*/

#include "my.h"
#include "shell.h"

void clear_node(list_t *node)
{
    free(node->data->key);
    free(node->data->value);
    free(node->data);
}

void unalloc_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

void free_confs(config_t *confs)
{
    free(confs->currpath);
    free(confs->hostname);
    free(confs);
}