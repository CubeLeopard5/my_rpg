/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_strsplit.c
*/

#include "minilib.h"
#include <stdlib.h>
#include <stddef.h>

// split str into a list, delimited by delim
char **my_strsplit(char *str, char delim)
{
    unsigned long i = 0;
    unsigned long element_len = 0;
    unsigned int arr_size = count_char_occurence(str, delim) + 1;
    char **arr = malloc(sizeof(char *) * (arr_size + 1));

    if (arr == NULL)
        return (NULL);
    for (unsigned int e = 0; e < arr_size; ++e, i += element_len + 1) {
        element_len = len_to_delim(&str[i], delim);
        arr[e] = malloc(sizeof(char) * (element_len + 1));
        if (arr[e] == NULL)
            return (NULL);
        my_strncpy(arr[e], &str[i], element_len);
        arr[e][element_len] = '\0';
    }
    arr[arr_size] = NULL;
    return (arr);
}

// destroy a char ** (ending with a NULL element)
void destroy_list(char **arr)
{
    if (arr == NULL)
        return;
    for (unsigned int i = 0; arr[i] != NULL; ++i)
        free(arr[i]);
    free(arr);
}

// count how many elements are in a list
unsigned int count_list(char **arr)
{
    unsigned int count = 0;

    if (arr != NULL)
        for (; arr[count] != NULL; ++count);
    return (count);
}
