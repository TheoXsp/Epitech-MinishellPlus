/*
** EPITECH PROJECT, 2021
** env init funcs for shell
** File description:
** env
*/

#include "my.h"
#include "shell.h"

static int get_var_len(var_t *data)
{
    int size = 0;

    size = (my_strlen(data->key) + my_strlen(data->value) + 1);
    return size;
}

static void set_to_env(list_t **env, char *str)
{
    var_t *data = malloc(sizeof(var_t));

    data->key = copy_from_to(str, 0, '=');
    data->value = copy_from_to(str, '=', 0);
    list_stack(env, data);
}

void init_env(list_t **listenv, char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        set_to_env(listenv, env[i]);
}

char **env_to_tab(list_t *lenv)
{
    int i = 0;
    int d = 0;
    int temppos = 0;
    int size = get_list_size(lenv);
    char **env = NULL;
    list_t *temp = lenv;

    env = malloc(sizeof(char *) * (size + 1));
    for (i = 0; temp != NULL; temp = temp->next, i++) {
        env[i] = malloc(sizeof(char) * (get_var_len(temp->data) + 2));
        for (d = 0; temp->data->key[d] != '\0'; d++)
            env[i][d] = temp->data->key[d];
        env[i][d] = '=';
        temppos = d + 1;
        for (d = 0; temp->data->value[d] != '\0'; d++, temppos++)
            env[i][temppos] = temp->data->value[d];
        env[i][temppos] = '\0';
    }
    env[size] = NULL;
    return env;
}