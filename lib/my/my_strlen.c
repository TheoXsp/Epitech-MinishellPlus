/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** Task 03 Day 04
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }

    return (i);
}
