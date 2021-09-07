/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** Concatenates n char of a string into another.
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int d = 0;

    while (dest[i] != '\0') {
        i++;
    }
    while (src[d] != '\0' && d < nb) {
        dest[i] = src[d];
        i++;
        d++;
    }
    return (dest);
}
