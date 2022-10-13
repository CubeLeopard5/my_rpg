/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_putnbr_tests.c
*/

#include "criterion_tests.h"

Test(my_putnbr, putnbr_test, .init = redirect_all_std)
{
    my_putnbr(916366378962432);
    my_putnbr(-916366378962432);
    cr_assert_stdout_eq_str("916366378962432-916366378962432");
}

Test(my_putunbr, putunbr_test, .init = redirect_all_std)
{
    my_putunbr(9223372036854775807);
    cr_assert_stdout_eq_str("9223372036854775807");
}

Test(my_fputnbr, fputnbr_test, .init = redirect_all_std)
{
    my_fputnbr(F_STDERR, 916366378962432);
    my_fputnbr(F_STDERR, -916366378962432);
    cr_assert_stderr_eq_str("916366378962432-916366378962432");
}

Test(my_fputunbr, fputunbr_test, .init = redirect_all_std)
{
    my_fputunbr(F_STDERR, 9223372036854775807);
    cr_assert_stderr_eq_str("9223372036854775807");
}