/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** Allocates mem to a string to cpy another one in it.
*/
#include<stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    int size = my_strlen(src);
    char *cpy = malloc(sizeof(char) * (size + 1));

    for (i = 0; src[i] != '\0'; i++) {
        cpy[i] = src[i];
    }
    cpy[i] = '\0';
    return (cpy);
}
