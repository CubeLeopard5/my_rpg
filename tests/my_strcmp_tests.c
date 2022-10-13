/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_strcmp_tests.c
*/

#include "criterion_tests.h"

Test(my_strcmp, compare_two_strings)
{
    char test1[] = "Hello world!\n";
    char test2[] = "Hello Criterion.";
    char test3[] = "";

    cr_assert_neq(my_strcmp(test1, test2), 0);
    cr_assert_neq(my_strcmp(test3, test1), 0);
    cr_assert_neq(my_strcmp(test2, test3), 0);
    cr_assert_eq(my_strcmp(test1, test1), 0);
    cr_assert_eq(my_strcmp(test2, test2), 0);
    cr_assert_eq(my_strcmp(test3, test3), 0);
}

Test(my_strncmp, compare_two_strings_up_to_n_chars)
{
    char test1[] = "Hello world!\n";
    char test2[] = "Hello Criterion.";
    char test3[] = "";

    cr_assert_neq(my_strncmp(test1, test2, 7), 0);
    cr_assert_neq(my_strncmp(test1, test3, 1), 0);
    cr_assert_neq(my_strncmp(test2, test3, 3), 0);
    cr_assert_eq(my_strncmp(test1, test1, 90), 0);
    cr_assert_eq(my_strncmp(test1, test2, 6), 0);
    cr_assert_eq(my_strncmp(test1, test3, 0), 0);
    cr_assert_eq(my_strncmp(test2, test2, my_strlen(test2)), 0);
}

Test(str_startsw, str_starts_with_pattern)
{
    char str[] = "Hello world!";
    char pat1[] = "Hello";
    char pat2[] = "world!";

    cr_assert_eq(str_startsw(str, pat1), true);
    cr_assert_eq(str_startsw(str, pat2), false);
    cr_assert_eq(str_startsw("", pat1), false);
    cr_assert_eq(str_startsw("test", "test"), true);
}

Test(str_endsw, str_ends_with_pattern)
{
    char str[] = "Hello world!";
    char pat1[] = "Hello";
    char pat2[] = "world!";

    cr_assert_eq(str_endsw(str, pat1), false);
    cr_assert_eq(str_endsw(str, pat2), true);
    cr_assert_eq(str_endsw("", pat1), false);
    cr_assert_eq(str_endsw("test", str), false);
    cr_assert_eq(str_endsw("test", "test"), true);
}