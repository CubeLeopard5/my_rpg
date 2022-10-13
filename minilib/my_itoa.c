/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_itoa.c
*/

#include "minilib.h"
#include <stdlib.h>
#include <stddef.h>

// write nbr in dest
void my_itos(char *dest, long nbr)
{
    int is_neg = nbr < 0;
    int i = 0;

    if (nbr == 0)
        dest[i++] = '0';
    if (is_neg)
        nbr *= -1;
    for (; nbr != 0; nbr /= 10, ++i)
        dest[i] = nbr % 10 + '0';
    if (is_neg)
        dest[i++] = '-';
    dest[i] = '\0';
    my_revstr(dest);
}

// write nbr in a char *
// returned char * is dynamically allocated, it needs to be freed
// returns NULL if malloc fails
char *my_itoa(long nbr)
{
    char *cnbr = malloc(sizeof(char) * (ML_ITOA_BUFSIZE + 1));

    if (cnbr == NULL)
        return (NULL);
    my_itos(cnbr, nbr);
    return (cnbr);
}

// write unsigned nbr in dest
void my_uitos(char *dest, unsigned long nbr)
{
    int i = 0;

    if (nbr == 0)
        dest[i++] = '0';
    for (; nbr != 0; nbr /= 10, ++i)
        dest[i] = nbr % 10 + '0';
    dest[i] = '\0';
    my_revstr(dest);
}

// write unsigned nbr in a char *
// returned char * is dynamically allocated, it needs to be freed
// returns NULL if malloc fails
char *my_uitoa(unsigned long nbr)
{
    char *cnbr = malloc(sizeof(char) * (ML_ITOA_BUFSIZE + 1));

    if (cnbr == NULL)
        return (NULL);
    my_uitos(cnbr, nbr);
    return (cnbr);
}