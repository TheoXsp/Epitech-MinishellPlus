/*
** EPITECH PROJECT, 2021
** confs funcs
** File description:
** configs
*/

#include "my.h"
#include "shell.h"

static char *parse_session(list_t *lenv)
{
    char *buffer = NULL;
    char *res = NULL;

    buffer = get_env_value(lenv, "SESSION_MANAGER");
    res = copy_from_to(buffer, '/', ':');
    free(buffer);
    return res;
}

config_t *init_confs(list_t *lenv)
{
    config_t *conf = malloc(sizeof(config_t));
    conf->hostname = parse_session(lenv);
    conf->currpath = get_env_value(lenv, "PWD");
    return conf;
}

char *update_confs(list_t *lenv, config_t *confs)
{
    char *buffer = NULL;

    free(confs->currpath);
    buffer = getcwd(buffer, 0);
    return buffer;
}