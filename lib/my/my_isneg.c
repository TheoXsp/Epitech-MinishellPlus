/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** Displays if input number is positiv or negativ.
*/

#include <unistd.h>
#include "my.h"

int my_isneg(int n)
{
    if (n == 0) {
        my_putchar('P');
    }
    else if (n >= 0) {
        my_putchar('P');
    }
    else {
        my_putchar('N');
    }
}
