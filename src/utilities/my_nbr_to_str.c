/*
** EPITECH PROJECT, 2020
** nbr to str
** File description:
** rpg
*/

#include "stddef.h"
#include "stdlib.h"

int get_nbr_len_sp(int i)
{
    int size;

    for (size = 0; i > 0; size++)
        i = i / 10;
    return (size);
}

char *my_nbr_to_str(int i)
{
    int size = get_nbr_len_sp(i);
    char *str = malloc(sizeof(char) * size + 1);

    if (i == 0)
        return ("0");
    for (int z = 0; z < size; z++) {
        str[size - 1 - z] = (i % 10 + 48);
        i = i / 10;
    }
    str[size] = '\0';
    return (str);
}