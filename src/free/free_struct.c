/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** free_struct
*/

#include "free.h"
#include "struct.h"
#include "SFML/Graphics.h"
#include "particles.h"

void free_struct(global_t *global)
{
    free_sound(global);
    free_environnement(global);
    make_it_rain_or_snow(global, 1, 5, 2);
}

void let_it_go_free(sfVector2f *position_array, int *velocity)
{
    free(velocity);
    free(position_array);
}