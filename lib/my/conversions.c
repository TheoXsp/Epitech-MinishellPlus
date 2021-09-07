/*
** EPITECH PROJECT, 2020
** conversions
** File description:
** conversions
*/

#include "my.h"
#include <stdarg.h>

void hexa(unsigned long int n, int type)
{
    char *res = malloc(sizeof(char) * 17);
    int rest = 0;
    int i = 0;

    for (; n != 0; i++) {
        rest = n % 16;
        res[i] = (rest < 10) ? rest + '0' : rest + '7';
        n /= 16;
    }
    res[i] = '\0';
    if (type == 0)
        my_putstr(my_revstr(res));
    else
        my_putstr(my_revstr(my_strlowcase(res)));
    free(res);
}

void octa(unsigned long int n)
{
    int d = 0;

    for (int i = 1; n != 0; i *= 10) {
        d += (n % 8) * i;
        n /= 8;
    }
    my_put_unsigned_nbr(d);
}

void binary(unsigned int n)
{
    int res[32];
    int rest = 0;
    int i = 0;

    for (; n != 0; i++) {
        res[i] = n % 2;
        n /= 2;
    }
    for (i -= 1; i >= 0; i--)
        my_put_nbr(res[i]);
}

void hash(va_list list, char *str, int *i)
{
    int res = 0;

    (*i)++;
    if (str[*i] == '#') {
        if (str[*i + 1] == 'X') {
            my_putstr("0X");
            hexa(va_arg(list, unsigned long int), 0);
        }
        else if (str[*i + 1] == 'x') {
            my_putstr("0x");
            hexa(va_arg(list, unsigned long int), 1);
        }
    }
    if (str[*i] == '+') {
        if (str[*i + 1] == 'd' || 'i') {
            my_putchar('+');
            my_put_nbr(va_arg(list, int));
        }
    }
}

void print_unprintable(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 127) {
            my_putchar('\\');
            octa(127);
        }
        else if (str[i] <= 31) {
            (str[i] < 8) ? (my_putstr("\\00"), octa((int)str[i]))
        : (my_putstr("\\0"), octa((int)str[i]));
        }
        else
            my_putchar(str[i]);
    }
}