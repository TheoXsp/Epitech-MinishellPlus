/*
** EPITECH PROJECT, 2021
** parsing core
** File description:
** parser
*/

#include "my.h"
#include "shell.h"

token_t delim[] =
{
    {" ", "", T_NORMAL, ID_SPACE},
    {"\t", "", T_NORMAL, ID_TAB},
    {"\"", "\"", T_DELIM, ID_DOUBLE_QUOTE},
    {"'", "'", T_DELIM, ID_SIMPLE_QUOTE},
    {"`", "`", T_DELIM, ID_BACK_QUOTE},
    {"(", ")", T_DELIM, ID_PARENTHESE},
    {">", "", T_GET, ID_RIGHT},
    {"|", "", T_GET, ID_PIPE},
    {"&", "", T_SEPARATOR, ID_BACKGROUND},
    {";", "", T_SEPARATOR, ID_SEP},
    {"<", "", T_SEPARATOR, ID_LEFT},
    {">&", "", T_NORMAL, ID_REDIRECTION},
    {">>", "", T_GET, ID_DOUBLE_RIGHT},
    {"<<", "", T_SEPARATOR, ID_DOUBLE_LEFT},
    {"||", "", T_SEPARATOR, ID_OR},
    {"&&", "", T_SEPARATOR, ID_AND},
    {NULL, NULL, ID_WITHOUT, ID_WITHOUT},
};

arg_t *is_delim(char *str, int *i)
{
    int tempid = 0;
    arg_t *temp = init_temp_arg(str[*i]);

    for (int d = 0; delim[d].token != NULL; d++)
        if (my_strncmp(delim[d].token, temp->token, 1) == 0) {
            temp->TYPE = delim[d].TYPE, temp->ID = delim[d].ID, (*i)++;
            break;
        }
    if (temp->TYPE == ID_WITHOUT) {
        clear_temp_arg(temp);
        return NULL;
    }
    if (!(temp->ID == ID_RIGHT || temp->ID == ID_LEFT ||
        temp->ID == ID_PIPE || temp->ID == ID_BACKGROUND))
        return temp;
    temp->token[1] = str[*i], temp->token[2] = '\0', tempid = temp->ID;
    for (int d = 0; delim[d].token != NULL; d++)
        if (my_strcmp(temp->token, delim[d].token) == 0)
            temp->ID = delim[d].ID, temp->TYPE = delim[d].TYPE, (*i)++;
    if (tempid == temp->ID) temp->token[1] = '\0';
    return temp;
}

arg_t *get_token(char *str, int *i, bool *errored)
{
    arg_t *arg = malloc(sizeof(arg_t));
    arg_t *temp = NULL;

    if ((temp = is_delim(str, i)) != NULL)
        arg->TYPE = temp->TYPE, arg->ID = temp->ID;
    else {
        set_string(arg, str, i);
        return arg;
    }
    if (arg->TYPE != T_NORMAL) {
        if (arg->TYPE != T_DELIM)
            arg->token = my_strdup(temp->token);
        else if (set_delim_str(arg, str, i, temp->token[0]) != 0) {
            clear_temp_arg(temp), free(arg), (*errored) = true;
            return NULL;
        }
        clear_temp_arg(temp);
        return arg;
    }
    clear_temp_arg(temp), free(arg);
    return NULL;
}

argslist_t *parser(char *str)
{
    argslist_t *args = NULL;
    arg_t *arg = NULL;
    bool errored = false;

    if (str[0] == '\0')
        return NULL;
    for (int i = 0; str[i] != '\n' && str[i] != '\0';) {
        if ((arg = get_token(str, &i, &errored)) != NULL)
            listarg_stack(&args, arg);
        if (errored == true) {
            listarg_destroy(args);
            args = NULL;
            break;
        }
        arg = NULL;
    }
    return args;
}