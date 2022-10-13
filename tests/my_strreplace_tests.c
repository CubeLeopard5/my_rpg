/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_strreplace_tests.c
*/

#include "criterion_tests.h"

Test(my_strreplace, replace_pattern)
{
    char input[] = "Hello world! 1, 2, 3, 4, 5.\n";
    char *rep1 = my_strreplace(input, "Hello", "Goodbye");
    char *rep2 = my_strreplace(input, " ", "_");
    char *rep3 = my_strreplace(input, " world", "");

    cr_assert_str_eq(rep1, "Goodbye world! 1, 2, 3, 4, 5.\n");
    cr_assert_str_eq(rep2, "Hello_world!_1,_2,_3,_4,_5.\n");
    cr_assert_str_eq(rep3, "Hello! 1, 2, 3, 4, 5.\n");
    free(rep1);
    free(rep2);
    free(rep3);
}

Test(my_strreplace, replace_inexistent_pattern)
{
    char input[] = "Hello world! 1, 2, 3, 4, 5.\n";
    char *rep1 = my_strreplace(input, "pattern", "wow");
    char *rep2 = my_strreplace(input, "", "");

    cr_assert_str_eq(rep1, input);
    cr_assert_neq(rep1, input);
    cr_assert_str_eq(rep2, input);
    free(rep1);
    free(rep2);
}

Test(my_strreplace_ptr, replace_ptr)
{
    char input[] = "Hello world! 1, 2, 3, 4, 5.\n";
    char *input_dup = input;
    char *dup = my_strdup(input);
    char *rep = dup;

    my_strreplace_ptr(&rep, "Hello", "Goodbye", true);
    my_strreplace_ptr(&input_dup, " ", "_", false);
    cr_assert_str_eq(rep, "Goodbye world! 1, 2, 3, 4, 5.\n");
    cr_assert_neq(rep, dup);
    cr_assert_str_eq(input_dup, "Hello_world!_1,_2,_3,_4,_5.\n");
    free(rep);
    free(input_dup);
}