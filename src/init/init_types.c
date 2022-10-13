/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_types
*/

#include "minilib.h"
#include "struct.h"
#include "stdio.h"
#include "stddef.h"
#include "function.h"
#include "my.h"
#include <stdlib.h>

char *get_next_line(FILE *file);

void init_types(global_t *global)
{
    FILE *file = fopen("assets/attacks/types_chart", "r");
    char *buf;
    int k = 0;

    global->type_chart = malloc(sizeof(int * ) * 19);
    get_next_line(file);
    for (int i = 0; i < 18; i++) {
        global->type_chart[i] = malloc(sizeof(int) * 19);
        buf = get_next_line(file);
        k = 2;
        for (int j = 0; j < 18; j++, k += 2) {
            global->type_chart[i][j] = buf[k] - 48;
        }
    }
    global->type_chart[18] = NULL;
}