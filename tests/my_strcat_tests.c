/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_strcat_tests.c
*/

#include "criterion_tests.h"

Test(my_strcat, append_str_to_another_str)
{
    char str[100];

    str[0] = '\0';
    my_strcat(str, "Test");
    my_strcat(str, " 1, 2, 3.");
    my_strcat(str, "\n");
    cr_assert_str_eq(str, "Test 1, 2, 3.\n");
}

Test(my_strncat, append_n_characters_to_str)
{
    char str[100];

    str[0] = '\0';
    my_strncat(str, "Test", 4);
    my_strncat(str, " 1, 2, 3.", 20);
    my_strncat(str, "\nUp to n chars!", 1);
    cr_assert_str_eq(str, "Test 1, 2, 3.\n");
}