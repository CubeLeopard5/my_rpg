/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_putstr_tests.c
*/

#include "criterion_tests.h"

Test(my_putstr, putstr_tests, .init = redirect_all_std)
{
    my_putstr("Hello world!\n");
    cr_assert_stdout_eq_str("Hello world!\n");
}

Test(my_fputstr, fputstr_tests, .init = redirect_all_std)
{
    my_fputstr(F_STDERR, "Hello world!\n");
    cr_assert_stderr_eq_str("Hello world!\n");
}