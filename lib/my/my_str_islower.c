/*
** EPITECH PROJECT, 2020
** my_str_islower
** File description:
** Indicates if the string only contains lowercase alpha char.
*/

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!(str[i] >= 'a' && str[i] <= 'z'))
            return (0);
        i++;
    }
    return (1);
}
