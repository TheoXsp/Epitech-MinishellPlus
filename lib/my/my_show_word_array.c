/*
** EPITECH PROJECT, 2020
** my_show_word_array
** File description:
** Displays the content of an array of words.
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        write(1, tab[i], my_strlen(tab[i]));
        my_putchar('\n');
    }
    return (0);
}
