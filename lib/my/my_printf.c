/*
** EPITECH PROJECT, 2020
** display std args
** File description:
** ~
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>



static void format_handler4(va_list list, char *str, int *i)
{
    long int res = 0;

    switch (str[*i + 1]) {
    case 'p' :
        res = va_arg(list, unsigned long int);
        (res == 0) ? my_putstr("(nil)") : (my_putstr("0x"), hexa(res, 1));
        break;
    case 'S' :
        print_unprintable(va_arg(list, char *));
        break;
    case '+' :
        hash(list, str, i);
        break;
    default :
        (str[*i + 1] == '\n') ? my_putchar(str[*i]), my_putchar('\n')
    : my_putchar(str[*i]);
        (str[*i + 1] != '\0' && str[*i + 1] != '\n')
        ? my_putchar(str[*i + 1]) : 0;
        break;
        (*i)++;
    }
}

static void format_handler3(va_list list, char *str, int *i)
{
    switch (str[*i + 1]) {
    case 'X' :
        hexa(va_arg(list, unsigned int), 0);
        break;
    case 'x' :
        hexa(va_arg(list, unsigned int), 1);
        break;
    case '#' :
        hash(list, str, i);
        break;
    case '%' :
        my_putchar('%');
        break;
    default :
        format_handler4(list, str, i);
        break;
        (*i)++;
    }
}

static void format_handler2(va_list list, char *str, int *i)
{
    switch (str[*i + 1]) {
    case 'u' :
        my_put_unsigned_nbr(va_arg(list, unsigned int));
        break;
    case 'i' :
        my_put_nbr(va_arg(list, int));
        break;
    case 'b' :
        binary(va_arg(list, unsigned int));
        break;
    case 'o' :
        octa(va_arg(list, unsigned long int));
        break;
    default :
        format_handler3(list, str, i);
        break;
        (*i)++;
    }
}

static void format_handler(va_list list, char *str, int *i)
{
    switch (str[*i + 1]) {
    case 'd' :
        my_put_nbr(va_arg(list, int));
        break;
    case 's' :
        my_putstr(va_arg(list, char *));
        break;
    case 'c' :
        my_putchar(va_arg(list, int));
        break;
    default :
        format_handler2(list, str, i);
        break;
    }
    (*i)++;
}

int my_printf(char *str, ...)
{
    int i = 0;
    va_list list;

    va_start(list, *str);
    for (i = 0; str[i] != '\0'; i++) {
        if (str [i] == '%')
            format_handler(list, str, &i);
        else
            my_putchar(str[i]);
    }
    va_end(list);
    return (i);
}