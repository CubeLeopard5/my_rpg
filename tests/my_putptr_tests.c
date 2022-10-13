/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_putptr_tests.c
*/

#include "criterion_tests.h"

Test(my_putptr, putptr_test, .init = redirect_all_std)
{
    my_putptr(0);
    my_putptr(1);
    cr_assert_stdout_eq_str("(nil)0x1");
}

Test(my_fputptr, fputptr_test, .init = redirect_all_std)
{
    my_fputptr(F_STDERR, 0);
    my_fputptr(F_STDERR, 1);
    cr_assert_stderr_eq_str("(nil)0x1");
}
