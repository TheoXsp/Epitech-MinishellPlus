/*
** EPITECH PROJECT, 2020
** my_h
** File description:
** My.h headers.
*/

#ifndef MY_H_
#define MY_H_
#include <stdarg.h>
#include <stdlib.h>

void my_put_nbr(int nb);

char *concat_params(int argc, char **argv);

int my_compute_power_rec(int nb, int p);

int my_compute_square_root(int nb);

int my_getnbr(char const *str);

int my_isneg(int n);

void my_putchar(char c);

void my_putstr(char const *str);

char *my_revstr(char *str);

int my_show_word_array(char * const *tab);

char *my_strcapitalize(char *str);

char *my_strcat(char *dest, char const *src);

char *my_strncat(char *dest, char const *src, int nb);

int my_strcmp(char const *s1, char const *s2);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src);

char *my_strncpy(char *dest, char const *src, int n);

int my_str_isalpha(char const *str);

int my_str_islower(char const *str);

int my_str_isnum(char const *str);

int my_str_isprintable(char const *str);

int my_str_isupper(char const *str);

int my_strlen(char const *str);

char *my_strlowcase(char *str);

char *my_strstr(char *str, char const *to_find);

char *my_strupcase(char *str);

void my_swap(int *a, int *b);

int my_printf(char *str, ...);

void my_put_unsigned_nbr(unsigned int nb);

void hexa(unsigned long int n, int type);

void octa(unsigned long int n);

void binary(unsigned int n);

void hash(va_list list, char *str, int *i);

void print_unprintable(char *str);

char **mem_alloc_2d_array(int nb_rows, int nb_cols);

#endif
