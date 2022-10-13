/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** paths.c
*/

#include "minilib.h"
#include <stdlib.h>
#include <stddef.h>

// get a pointer to the start of the filename in path
char *get_filename(char *path)
{
    unsigned long i = my_strlen(path);

    for (; i > 0; --i) {
        if (path[i - 1] == '/')
            return (&path[i]);
    }
    return (path);
}

// join base and path, adding/removing slashes as needed
// this function dynamically allocates the returned char *
// it needs to be freed
char *join_path(char *base, char *path)
{
    bool base_slash = str_endsw(base, "/");
    bool path_slash = str_startsw(path, "/");
    unsigned long joined_len = my_strlen(base) + my_strlen(path) + 2;
    char *joined = malloc(sizeof(char) * joined_len);

    if (!joined)
        return (NULL);
    my_strcpy(joined, base);
    if (!base_slash && !path_slash) {
        my_strcat(joined, "/");
    }
    if (base_slash && path_slash) {
        my_strcat(joined, &path[1]);
    } else {
        my_strcat(joined, path);
    }
    return (joined);
}