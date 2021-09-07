/*
** EPITECH PROJECT, 2021
** env funcs for shell
** File description:
** env
*/

#include "my.h"
#include "shell.h"

char *get_env_value(list_t *lenv, char *key)
{
    list_t *temp = lenv;

    for (; temp != NULL; temp = temp->next)
        if (my_strcmp(temp->data->key, key) == 0)
            return my_strdup(temp->data->value);
    return NULL;
}

void update_env_value(list_t *lenv, char *key, char *value)
{
    list_t *temp = lenv;

    for (; temp != NULL; temp = temp->next)
        if (my_strcmp(temp->data->key, key) == 0)
            break;
    if (temp == NULL)
        return;
    free(temp->data->value);
    temp->data->value = value;
}

void env_add(list_t **lenv, char *key, char *value)
{
    var_t *data = malloc(sizeof(var_t));

    data->key = my_strdup(key);
    data->value = my_strdup(value);
    list_stack(lenv, data);
}