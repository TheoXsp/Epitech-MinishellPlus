/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** Finds occurence of a string in another string.
*/
#include "my.h"

static int get_let(int d, int i, char *str, char const *to_find)
{
    if (str[i + d] == to_find[d])
        return (1);
    else
        return (0);
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int d = 0;
    int let = 1;

    for (; str[i] != '\0'; i++) {
        if (str[i] == to_find[0])
            let = 1;
        for (d = 0; to_find[d] != '\0' && let == 1; d++) {
            let = get_let(d, i, str, to_find);
        }
        if (let == 1) {
            return &str[i];
        }
    }
    return (0);
}
