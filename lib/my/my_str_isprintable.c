/*
** EPITECH PROJECT, 2020
** my_str_isprintable
** File description:
** Indicates if the string only contains printable char.
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!(str[i] > 31 && str[i] < 127))
            return (0);
        i++;
    }
    return (1);
}