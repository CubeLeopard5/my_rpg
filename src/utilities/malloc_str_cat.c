/*
** EPITECH PROJECT, 2020
** my str cat
** File description:
** concatenate two str
*/

#include "stddef.h"
#include "stdlib.h"

int my_strlen(char *str);

char *malloc_strcat(char *a, char *b)
{
    char *res = malloc(sizeof(char) * (my_strlen(a) + my_strlen(b) + 1));
    int i = 0;

    for (i = 0; a[i] != '\0'; i++) {
        res[i] = a[i];
    }
    for (int n = 0; b[n] != '\0'; n++) {
        res[i] = b[n];
        i++;
    }
    res[i] = '\0';
    return (res);
}