/*
** EPITECH PROJECT, 2020
** concat_params
** File description:
** Turn the command line given into a single string.
*/
#include<stdlib.h>

void my_putstr(char const *str);

int my_strlen(char const *str);

static int get_size(int argc, char **argv)
{
    int size = 0;

    for (int i = 0; i < argc; i++) {
        size += my_strlen(argv[i]);
    }
    return (size);
}

char *concat_params(int argc, char **argv)
{
    int count = 0;
    int size = get_size(argc, argv);
    char *params;
    int d = 0;
    int i = 0;

    params = malloc(sizeof(char) * (size + i));
    for (i = 0; i < argc; i++) {
        for (; argv[i][d] != '\0'; d++) {
            params[count] = argv[i][d];
            count++;
        }
        if (i < argc - 1) {
            params[count] = '\n';
            count++;
        }
        d = 0;
    }
    return (params);
}
