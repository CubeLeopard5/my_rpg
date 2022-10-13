/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_putbase_tests.c
*/

#include "criterion_tests.h"

Test(my_putbase, putbase_tests, .init = redirect_all_std)
{
    my_putbase(9, "01");
    my_putbase(254, "0123456789ABCDEF");
    cr_assert_stdout_eq_str("1001FE");
}

Test(my_fputbase, fputbase_tests, .init = redirect_all_std)
{
    my_fputbase(F_STDERR, 9, "01");
    my_fputbase(F_STDERR, 254, "0123456789ABCDEF");
    cr_assert_stderr_eq_str("1001FE");
}

Test(my_puthex, puthex_tests, .init = redirect_all_std)
{
    my_puthex(9163663789624328, true);
    my_puthex(9163663789624328, false);
    cr_assert_stdout_eq_str("208E4DBD058C08208e4dbd058c08");
}

Test(my_fputhex, fputhex_tests, .init = redirect_all_std)
{
    my_fputhex(F_STDERR, 9163663789624328, true);
    my_fputhex(F_STDERR, 9163663789624328, false);
    cr_assert_stderr_eq_str("208E4DBD058C08208e4dbd058c08");
}