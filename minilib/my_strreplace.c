/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_strreplace.c
*/

#include "minilib.h"
#include <stdlib.h>
#include <stddef.h>

// return a string with every occurence of pattern from str replaced with
// replace
char *my_strreplace(char *str, char *pattern, char *replace)
{
    unsigned long count = count_pattern_occurence(str, pattern);
    unsigned long str_len = my_strlen(str);
    unsigned long patlen = my_strlen(pattern);
    unsigned long total_replen = my_strlen(replace) * count;
    unsigned long dest_len = str_len - (patlen * count) + total_replen;
    char *dest = malloc(sizeof(char) * (dest_len + 1));
    unsigned long element_len = 0;
    unsigned long r = 0;

    if (!dest)
        return (NULL);
    dest[0] = '\0';
    for (unsigned long i = 0; i < str_len; i += patlen + element_len, ++r) {
        element_len = len_to_pattern(&str[i], pattern);
        my_strncat(dest, &str[i], element_len);
        if (r < count)
            my_strcat(dest, replace);
    }
    return (dest);
}

// replace every occurence of pattern from str with replace and set *str
// to the dynamically allocated string
// if free_old is set, the original *str pointer will be freed
void my_strreplace_ptr(char **str, char *pattern, char *replace,
    bool free_old)
{
    char *nstr = my_strreplace(*str, pattern, replace);

    if (nstr == NULL)
        return;
    if (free_old)
        free(*str);
    *str = nstr;
}