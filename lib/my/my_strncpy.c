/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** Copies N char of a string in another one.
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i != n; i++) {
        dest[i] = src[i];
    }
    return (dest);
}
