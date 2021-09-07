/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** Reverse a String.
*/

#include "my.h"

char *my_revstr(char *str)
{
    int last = my_strlen(str) - 1;
    char c;

    for (int i = 0; i < last; i++, last--) {
        c = str[i];
        str[i] = str[last];
        str[last] = c;
    }
    return (str);
}
