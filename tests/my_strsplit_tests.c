/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_strsplit_tests.c
*/

#include "criterion_tests.h"

Test(my_strsplit, split_str_and_free)
{
    char teststr[] = "this is a test";
    char **splitted = my_strsplit(teststr, ' ');

    cr_assert_str_eq(splitted[0], "this");
    cr_assert_str_eq(splitted[1], "is");
    cr_assert_str_eq(splitted[2], "a");
    cr_assert_str_eq(splitted[3], "test");
    cr_assert_eq(splitted[4], NULL);
    destroy_list(splitted);
}

Test(my_strsplit, split_str_special)
{
    char teststr[] = "this   is   a    test";
    char **splitted = my_strsplit(teststr, ' ');

    cr_assert_str_eq(splitted[0], "this");
    for (unsigned int i = 0; splitted[i] != NULL; ++i);
    destroy_list(splitted);
}

Test(my_strsplit, split_flat_str_and_free)
{
    char teststr[] = "hellothereisnodelimiterhere";
    char **splitted = my_strsplit(teststr, ' ');

    cr_assert_str_eq(splitted[0], "hellothereisnodelimiterhere");
    cr_assert_eq(splitted[1], NULL);
    destroy_list(splitted);
}

Test(my_strsplit, error_handling)
{
    char teststr[] = "";
    char **splitted = my_strsplit(teststr, ' ');

    cr_assert_str_eq(splitted[0], "");
    cr_assert_eq(splitted[1], NULL);
    cr_assert_eq(count_list(splitted), 1);
    destroy_list(splitted);
}

Test(count_list, count_split_list)
{
    char teststr[] = "this is a test";
    char **splitted = my_strsplit(teststr, ' ');

    cr_assert_str_eq(splitted[0], "this");
    cr_assert_str_eq(splitted[1], "is");
    cr_assert_str_eq(splitted[2], "a");
    cr_assert_str_eq(splitted[3], "test");
    cr_assert_eq(splitted[4], NULL);
    cr_assert_eq(count_list(splitted), 4);
    cr_assert_eq(count_list(NULL), 0);
    destroy_list(splitted);
}