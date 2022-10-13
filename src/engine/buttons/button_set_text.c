/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** button_set_text.c
*/

#include "engine.h"

// set button text
void button_set_text(button_t *button, char *text)
{
    sfVector2f position = sfRectangleShape_getPosition(button->shape);

    sfText_setString(button->text, text);
    button_set_position(button, position);
}