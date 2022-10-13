/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** str_op.c
*/

#include "minilib.h"
#include <stddef.h>

// count how many times pattern appears in str
unsigned long count_pattern_occurence(char *str, char *pattern)
{
    char *next = my_strstr(str, pattern);
    unsigned long count = 0;

    for (; next != NULL; ++count)
        next = my_strstr(&next[1], pattern);
    return (count);
}

// count how many times c appears in str
unsigned long count_char_occurence(char *str, char c)
{
    unsigned long count = 0;

    for (unsigned long i = 0; str[i] != '\0'; ++i) {
        if (str[i] == c)
            count += 1;
    }
    return (count);
}

// return length between *str to first pattern
unsigned long len_to_pattern(char *str, char *pattern)
{
    char *next = my_strstr(str, pattern);

    return next ? (unsigned long) (next - str) : my_strlen(str);
}

// return length between *str to first delim
unsigned long len_to_delim(char *str, char delim)
{
    unsigned long i = 0;

    for (; str[i] != delim && str[i] != '\0'; ++i);
    return (i);
}