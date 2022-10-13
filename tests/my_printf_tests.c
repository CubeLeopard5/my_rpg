/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_printf_basic.c
*/

#include "criterion_tests.h"

Test(my_printf, printf_char_str, .init = redirect_all_std)
{
    my_printf("Testing %s, %c%col!\n", "my_printf", 'c', 'o');
    my_fprintf(F_STDERR, "Testing %s, %c%col!\n", "my_printf", 'c', 'o');
    cr_assert_stdout_eq_str("Testing my_printf, cool!\n");
    cr_assert_stderr_eq_str("Testing my_printf, cool!\n");
}

Test(my_printf, prinf_numbers, .init = redirect_all_std)
{
    my_printf("%i!=%ubut%d==%i", -890, 84, 193123019, 193123019);
    my_fprintf(F_STDERR, "%i!=%ubut%d==%i", -930, 84, 193123019, 193123019);
    cr_assert_stdout_eq_str("-890!=84but193123019==193123019");
    cr_assert_stderr_eq_str("-930!=84but193123019==193123019");
}

Test(my_printf, printf_hex, .init = redirect_all_std)
{
    my_printf("%x != %X", 255, 983147);
    my_fprintf(F_STDERR, "%X == %x", 839128780, 839128780);
    cr_assert_stdout_eq_str("ff != F006B");
    cr_assert_stderr_eq_str("320416CC == 320416cc");
}

Test(my_printf, printf_ptr, .init = redirect_all_std)
{
    char test_pr[] = "";

    my_printf("%p is the answer to %p ", 0, 42);
    my_fprintf(F_STDERR, "%p -> %p", test_pr, 0);
    cr_assert_stdout_eq_str("(nil) is the answer to 0x2a ");
}

Test(my_printf, printf_special_cases, .init = redirect_all_std)
{
    my_printf("%i% of tests %ai% %%% should succeed\n", 100);
    my_fprintf(F_STDERR, "%i% of tests %ai% %%% should succeed\n", 100);
    cr_assert_stdout_eq_str("100% of tests %ai% %%% should succeed\n");
    cr_assert_stderr_eq_str("100% of tests %ai% %%% should succeed\n");
}