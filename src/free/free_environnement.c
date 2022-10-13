/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** free_environnement
*/

#include "free.h"
#include <stdlib.h>

static void free_forest(global_t *global, int i)
{
    for (int j = 0; j < 6; j++) {
        sfSprite_destroy( global->env_spr[i][j]);
    }
}

void free_environnement(global_t *global)
{
    free_forest(global, 1);
    for (int i = 0; i < 4; i++) {
        free(global->env_spr[i]);
    }
    free(global->env_spr);
}