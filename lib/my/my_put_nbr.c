/*
** EPITECH PROJECT, 2020
** my_putnbr
** File description:
** Puts a number.
*/
#include <unistd.h>
#include "my.h"

void my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return;
    }
    if (nb >= 0 && nb < 10)
        my_putchar(nb + '0');
    else if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb * (-1));
    }
    else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
}