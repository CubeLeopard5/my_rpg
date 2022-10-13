/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** button_position.c
*/

#include "engine.h"
#include "minilib.h"

// change button position
void button_set_position(button_t *button, sfVector2f position)
{
    sfVector2f button_pos = {.x = position.x, .y = position.y};
    sfVector2f shape_size = sfRectangleShape_getSize(button->shape);
    unsigned int character_size = sfText_getCharacterSize(button->text);
    unsigned long tlen = my_strlen((char *) sfText_getString(button->text));

    button_pos.x += (shape_size.x - tlen * (character_size / 1.4)) / 2;
    if (button_pos.x < position.x)
        button_pos.x = position.x;
    button_pos.y += shape_size.y / 2 - character_size / 2;
    sfRectangleShape_setPosition(button->shape, position);
    sfText_setPosition(button->text, button_pos);
}