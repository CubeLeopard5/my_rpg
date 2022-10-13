/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** conversion
*/

#include "SFML/Graphics.h"

sfVector2i vector_float_to_int(sfVector2f vec_float)
{
    sfVector2i vec_int;

    vec_int.x = (int)vec_float.x;
    vec_int.y = (int)vec_float.y;
    return (vec_int);
}

sfVector2f vector_int_to_float(sfVector2i vec_int)
{
    sfVector2f vec_float;

    vec_float.x = (float)vec_int.x;
    vec_float.y = (float)vec_int.y;
    return (vec_float);
}
