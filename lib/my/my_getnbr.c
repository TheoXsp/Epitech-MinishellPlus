/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** Takes a string and turn it into an int if possible.
*/

#include "my.h"
#include <unistd.h>

static int need_check(const char *str, int i)
{
    if (i == 0)
        return 0;
    else if (str[i - 1] == '-')
        return 1;
}

static int checkneg(char const *str, int i)
{
    int isneg = 0;
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            isneg++;
        i--;
    }
    if (isneg % 2 == 0)
        return (0);
    else
        return (1);
}

static int checklen(int first, long long res)
{
    if (first == 0 && (res >= (-2147483648) && res <= 2147483647))
        return (res);
    else if (first == 1 && (res >= (-2147483648) && res <= 2147483648))
        return ((res) * (-1));
    else
        return (0);
}

int my_getnbr(char const *str)
{
    long long res = 0;
    int first = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        while ((str[i] < '0' && str[i] > '9'))
            i++;
        if (need_check(str, i) == 1)
            first = checkneg(str, i - 1);
        if ((str[i] >= '0' && str[i] <= '9')) {
            res += str[i] - '0';
            res *= 10;
        }
        if ((str[i] >= '0' && str[i] <= '9')
        && (str[i + 1] < '0' || str[i + 1] > '9')) {
            res /= 10;
            return (res = checklen(first, res));
        }
    }
    return (0);
}