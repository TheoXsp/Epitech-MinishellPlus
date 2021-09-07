/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** Copies string content to another.
*/

#include<unistd.h>

char *my_strcpy(char *dest, char const *src)
{
    int d = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
        d++;
    }
    dest[d] = '\0';
    return (dest);
}
