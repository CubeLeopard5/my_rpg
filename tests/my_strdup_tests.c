/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_strdup_tests.c
*/

#include "criterion_tests.h"

Test(my_strdup, duplicate_string)
{
    char str[] = "Hello world!";
    char *dupped = my_strdup(str);

    cr_assert_neq(str, dupped);
    cr_assert_str_eq(str, dupped);
    free(dupped);
}