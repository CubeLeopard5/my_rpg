/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_itoa_tests.c
*/

#include "criterion_tests.h"

Test(my_itoa, my_itoa)
{
    char *zero = my_itoa(0);
    char *nbr = my_itoa(1234569031);
    char *nbr_neg = my_itoa(-1231238456);

    cr_assert_str_eq(zero, "0");
    cr_assert_str_eq(nbr, "1234569031");
    cr_assert_str_eq(nbr_neg, "-1231238456");
    free(zero);
    free(nbr);
    free(nbr_neg);
}

Test(my_uitoa, my_uitoa)
{
    char *zero = my_uitoa(0);
    char *nbr = my_uitoa(7632199127362);
    char *nbr2 = my_uitoa(123456789);

    cr_assert_str_eq(zero, "0");
    cr_assert_str_eq(nbr, "7632199127362");
    cr_assert_str_eq(nbr2, "123456789");
    free(zero);
    free(nbr);
    free(nbr2);
}