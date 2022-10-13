/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_strstr_tests.c
*/

#include "criterion_tests.h"

Test(my_strstr, find_pattern_ptr)
{
    char str[] = "Hello programming world!\n";
    char *ptr = my_strstr(str, "program");
    char *ptr2 = my_strstr(ptr, " ");

    cr_assert_str_eq(ptr, "programming world!\n");
    cr_assert_str_eq(ptr2, " world!\n");
}

Test(my_strstr, find_non_existent_pattern)
{
    char str[] = "Hello world!";
    char *ptr = my_strstr(str, "saucisse");

    cr_assert_eq(ptr, NULL);
}