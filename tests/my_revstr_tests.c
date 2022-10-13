/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_revstr_tests.c
*/

#include "criterion_tests.h"

Test(my_revstr, my_revstr)
{
    char test1[] = "1234567890";
    char test2[] = "";
    char test3[] = "This is a longer test\n";
    char test4[] = "kayaK\0this doesn't exist";

    cr_assert_eq(test1, my_revstr(test1));
    cr_assert_eq(test2, my_revstr(test2));
    cr_assert_eq(test3, my_revstr(test3));
    cr_assert_eq(test4, my_revstr(test4));
    cr_assert_str_eq(test1, "0987654321");
    cr_assert_str_eq(test2, "");
    cr_assert_str_eq(test3, "\ntset regnol a si sihT");
    cr_assert_str_eq(test4, "Kayak");
}