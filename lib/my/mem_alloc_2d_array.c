/*
** EPITECH PROJECT, 2020
** mem alloc 2d
** File description:
** mem_alloc_2d_array
*/

#include "my.h"

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **dest = malloc(sizeof(char *) * (nb_cols + 1));

    for (int i = 0; i < nb_cols; i++)
        dest[i] = malloc(sizeof(char) * (nb_rows + 1));
    return (dest);
}