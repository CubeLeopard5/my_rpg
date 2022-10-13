/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** button_destroy.c
*/

#include "engine.h"

// free memory allocated for button
void button_destroy(button_t *button)
{
    sfRectangleShape_destroy(button->shape);
    sfText_destroy(button->text);
    sfFont_destroy(button->font);
    free(button);
}