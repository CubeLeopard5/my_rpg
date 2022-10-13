/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_atoi_tests.c
*/

#include "criterion_tests.h"

Test(my_atoi, my_atoi)
{
    long zero = my_atoi("0");
    long nbr1 = my_atoi("123456789");
    long nbr2 = my_atoi("-123456789");

    cr_assert_eq(zero, 0);
    cr_assert_eq(nbr1, 123456789);
    cr_assert_eq(nbr2, -123456789);
}

Test(my_atoi, my_atoi_error)
{
    long error = my_atoi("-42.");
    long error2 = my_atoi("err1-0or");

    cr_assert_eq(error, 0);
    cr_assert_eq(error2, 0);
}

Test(my_atoui, my_atoui)
{
    unsigned long zero = my_atoui("0");
    unsigned long nbr1 = my_atoui("123456789");
    unsigned long nbr2 = my_atoui("98321973021738");

    cr_assert_eq(zero, 0);
    cr_assert_eq(nbr1, 123456789);
    cr_assert_eq(nbr2, 98321973021738);
}

Test(my_atoui, my_atoui_error)
{
    unsigned long error = my_atoui("42.");
    unsigned long error2 = my_atoui("err10or");

    cr_assert_eq(error, 0);
    cr_assert_eq(error2, 0);
}