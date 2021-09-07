/*
** EPITECH PROJECT, 2020
** my_strcapitalize
** File description:
** Put each first letter of each word in uppercase.
*/

static void my_upcase(char *str, int i)
{
    if (str[i - 1] == 45 || str[i - 1] == 43 || str[i - 1] == 32)
        str[i] -= 32;
}

char *my_strcapitalize(char *str)
{
    int i = 1;
    if (str[0] >= 97 && str[0] <= 122)
        str[0] -= 32;

    while (str[i] != '\0') {
        if (str[i] >= 97 && str[i] <= 122) {
            my_upcase(str, i);
        }
        else if (str[i] >= 65 && str[i] <= 90) {
            str[i] += 32;
        }
        i++;
    }
    return (str);
}
