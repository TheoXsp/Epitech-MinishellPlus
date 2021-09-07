/*
** EPITECH PROJECT, 2020
** my_putnbr
** File description:
** Puts a number.
*/
#include <unistd.h>
#include "my.h"

void my_put_unsigned_nbr(unsigned int nb)
{
    if (nb >= 0 && nb < 10)
        my_putchar(nb + '0');
    else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
}