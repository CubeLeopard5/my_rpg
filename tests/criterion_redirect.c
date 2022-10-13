/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** criterion_redirect.c
*/

#include "criterion_tests.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
