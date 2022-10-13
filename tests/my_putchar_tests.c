/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_putchar_tests.c
*/

#include "criterion_tests.h"

Test(my_putchar, putchar_tests, .init = redirect_all_std)
{
    my_putchar('H');
    my_putchar('e');
    my_putchar('l');
    my_putchar('l');
    my_putchar('o');
    my_putchar('!');
    cr_assert_stdout_eq_str("Hello!");
}

Test(my_fputchar, fputchar_tests, .init = redirect_all_std)
{
    my_fputchar(F_STDERR, 'H');
    my_fputchar(F_STDERR, 'e');
    my_fputchar(F_STDERR, 'l');
    my_fputchar(F_STDERR, 'l');
    my_fputchar(F_STDERR, 'o');
    my_fputchar(F_STDERR, '!');
    cr_assert_stderr_eq_str("Hello!");
}