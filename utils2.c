/*
** EPITECH PROJECT, 2021
** more utils for the shell
** File description:
** utils2
*/

#include "my.h"
#include "shell.h"

int get_args_nbr(char **args)
{
    int i = 0;

    for (i = 0; args[i] != NULL; i++);
    return i;
}

char **alloc_arg_tab(char *str, int size, char delim)
{
    int d = 0;
    char **res = malloc(sizeof(char *) * (size + 1));

    for (int i = 0, size = 0; str[i] != '\0'; i++) {
        if (str[i] != delim && str[i] != '"')
            size++;
        if (str[i] == delim || str[i + 1] == '\0') {
            res[d] = malloc(sizeof(char) * (size + 1));
            d++;
            size = 0;
        }
    }
    return res;
}

int set_quote_str(char **res, char *str, int *i, int d)
{
    int count = 0;

    (*i) = (*i) += 1;
    for (; str[*i] != '"' && str[*i] != '\0'; (*i)++, count++)
        res[d][count] = str[*i];
    if (str[*i] == '\0')
        count = -1;
    return count + 1;
}