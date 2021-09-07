/*
** EPITECH PROJECT, 2021
** parser utils funcs
** File description:
** parser_utils
*/

#include "my.h"
#include "shell.h"

void clear_temp_arg(arg_t *temp)
{
    if (temp != NULL) {
        free(temp->token);
        free(temp);
    }
}

arg_t *init_temp_arg(char c)
{
    arg_t *temp = malloc(sizeof(arg_t));

    temp->token = malloc(sizeof(char) * 3);
    temp->ID = ID_WITHOUT;
    temp->TYPE = ID_WITHOUT;
    temp->token[0] = c;
    temp->token[1] = '\0';
    return temp;
}

int set_delim_str(arg_t *arg, char *str, int *i, char delim)
{
    int temp = *i;
    int d = 0;

    for (; str[temp] != delim && str[temp] != '\n'; temp++);
    if (str[temp] == '\n') {
        my_printf("Unmatched '%c'.\n", delim);
        (*i) = temp;
        return 1;
    }
    arg->token = malloc(sizeof(char) * (temp - (*i) + 1));
    arg->TYPE = ID_WITHOUT;
    arg->ID = ID_WITHOUT;
    for (d = 0; str[*i] != delim; (*i)++, d++)
        arg->token[d] = str[*i];
    arg->token[d] = '\0';
    (*i)++;
    return 0;
}

void set_string(arg_t *arg, char *str, int *i)
{
    arg_t *temparg = NULL;
    int temp = *i;
    int d = 0;
    char delim = 0;

    arg->TYPE = ID_WITHOUT;
    arg->ID = ID_WITHOUT;
    while ((temparg = is_delim(str, &temp)) == NULL && str[temp] != '\n')
        temp++;
    arg->token = malloc(sizeof(char) * (temp - (*i) + 1));
    if (temparg) {
        delim = temparg->token[0];
        clear_temp_arg(temparg);
    }
    for (d = 0; str[*i] != delim && str[*i] != '\n'; (*i)++, d++)
        arg->token[d] = str[*i];
    arg->token[d] = '\0';
}