/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** button_clicked.c
*/

#include "engine.h"

// determine if button is clicked
sfBool button_pointed(button_t *button, sfVector2f mouse_click)
{
    sfVector2f pos = sfRectangleShape_getPosition(button->shape);
    sfVector2f size = sfRectangleShape_getSize(button->shape);

    if (mouse_click.x < pos.x || mouse_click.x > pos.x + size.x)
        return sfFalse;
    if (mouse_click.y < pos.y || mouse_click.y > pos.y + size.y)
        return sfFalse;
    return sfTrue;
}