/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** button_set_color.c
*/

#include "engine.h"

// set button color
void button_set_color(button_t *button, sfColor button_color)
{
    sfRectangleShape_setFillColor(button->shape, button_color);
}

// set button colors
void button_set_colors(button_t *button, sfColor button_color,
    sfColor hover_color)
{
    button->button_color = button_color;
    button->hover_color = hover_color;
}