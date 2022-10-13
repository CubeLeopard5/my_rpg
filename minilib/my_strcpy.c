/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_strcpy.c
*/

#include "minilib.h"

// copy contents of src to dest
char *my_strcpy(char *dest, char *src)
{
    unsigned long i = 0;

    for (; src[i] != '\0'; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

// copy up to n characters (from the beginning) from src to dest
char *my_strncpy(char *dest, char *src, unsigned long n)
{
    unsigned long i = 0;

    for (; i < n && src[i] != '\0'; ++i)
        dest[i] = src[i];
    for (; i < n; ++i)
        dest[i] = '\0';
    return (dest);
}
