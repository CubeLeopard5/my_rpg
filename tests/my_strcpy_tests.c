/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_strcpy_tests.c
*/

#include "criterion_tests.h"

Test(my_strcpy, my_strcpy_test)
{
    char src[] = "Hello world!";
    char dest[my_strlen(src) + 1];

    my_strcpy(dest, src);
    cr_assert_str_eq(dest, src);
}

Test(my_strncpy, my_strncpy_test)
{
    char src[] = "Hello world!";
    char dest[6];

    dest[5] = '@';
    my_strncpy(dest, src, 5);
    for (int i = 0; i < 5; ++i)
        cr_assert_eq(dest[i], src[i]);
    cr_assert_eq(dest[5], '@');
}

Test(my_strncpy, my_strncpy_n_overflow)
{
    char src[] = "Hello world!";
    char dest[32];

    my_strncpy(dest, src, 32);
    cr_assert_str_eq(dest, src);
    for (int i = 13; i < 32; ++i)
        cr_assert_eq(dest[i], '\0');
}