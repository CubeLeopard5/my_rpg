/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** button_render.c
*/

#include "engine.h"

// render a button
void button_render(sfRenderWindow *window, button_t *button)
{
    sfRenderWindow_drawRectangleShape(window, button->shape, NULL);
    sfRenderWindow_drawText(window, button->text, NULL);
}