/*
** EPITECH PROJECT, 2019
** bubble_text_tweaks.c
** File description:
** text says whaaat
*/

#include "sflib_f.h"

int my_strlen(char *str);

void bubble_text_replacing(const char *base_text, char *textyno,
int yno, int n)
{
    if (n != -1) {
        textyno[yno] = base_text[n];
        textyno[yno + 1] = '\0';
    }
    else {
        textyno[yno] = '\n';
        textyno[yno + 1] = '\n';
        textyno[yno + 2] = '\0';
    }
}

int bubble_text_3(const char *base_text, char *textyno, int is_new_text)
{
    static int *nb;

    if (is_new_text == 1) {
        nb = malloc(sizeof(int *) * 3);
        for (int i = 0; i != 3 ; i++)
            nb[i] = 0;
        return (0);
    }
    if (my_strlen(textyno) > 43)
        for (int i = 1; i != 3 ; i++)
            nb[i] = 0;
    if (my_strlen(textyno) > 20 && nb[1] == 0 && my_strlen(textyno) <= 43) {
        nb[1] = 1;
        bubble_text_replacing(base_text, textyno, nb[2], -1);
        nb[2] += 2;
    }
    bubble_text_replacing(base_text, textyno, nb[2], nb[0]);
    nb[0]++;
    nb[2]++;
    return (0);
}