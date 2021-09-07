/*
** EPITECH PROJECT, 2021
** utils funcs for shell
** File description:
** utils
*/

#include "my.h"
#include "shell.h"

static int get_alloc_size(char *str, char delim)
{
    int size = 1;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == delim)
            size++;
    return size;
}

static void init_new_str(char **res, int *d, int *count)
{
    res[*d][*count] = '\0';
    (*d)++;
    (*count) = -1;
}

char **str_to_arr(char *str, char delim)
{
    int size = get_alloc_size(str, delim) + 1;
    char **res = alloc_arg_tab(str, size, delim);
    int d = 0;
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++, count++) {
        if (str[i] == '"' && str[i + 1] != '\0')
            count = set_quote_str(res, str, &i, d) - 2;
        if (count < 0) {
            my_printf("Unmatched '\"'.\n");
            return NULL;
        }
        if (str[i] != delim && str[i] != '"')
            res[d][count] = str[i];
        else if (str[i] == delim)
            init_new_str(res, &d, &count);
        if (str[i + 1] == '\0')
            res[d][count + 1] = '\0';
    }
    res[d + 1] = NULL;
    return res;
}

int get_list_size(list_t *list)
{
    int size = 0;
    list_t *temp = list;

    for (; temp != NULL; temp = temp->next, size++);
    return size;
}

char *copy_from_to(char *str, char start, char delim)
{
    int i = 0;
    int temp = 0;
    int size = 0;
    char *buffer = NULL;

    if (start == 0) {
        for (; str[size] != delim; size++);
        buffer = malloc(sizeof(char) * (size + 1));
        for (i = 0; str[i] != delim; i++)
            buffer[i] = str[i];
    }
    else {
        for (; str[i] != start; i++);
        temp = i + 1;
        for (; str[i] != delim; size++, i++);
        buffer = malloc(sizeof(char) * (size + 1));
        for (i = 0; str[temp] != delim; temp++, i++)
            buffer[i] = str[temp];
    }
    buffer[i] = '\0';
    return buffer;
}