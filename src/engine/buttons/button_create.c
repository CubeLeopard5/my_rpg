/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** button_create.c
*/

#include "engine.h"

void button_init(button_t *button, char *text, char *font,
sfColor color)
{
    sfVector2f position = {.x = 0, .y = 0};
    sfVector2f size = {.x = 350, .y = 100};

    sfText_setFont(button->text, button->font);
    sfText_setString(button->text, text);
    sfText_setCharacterSize(button->text, 20);
    sfRectangleShape_setSize(button->shape, size);
    button_set_colors(button, color, color);
    button_set_color(button, color);
    button_set_position(button, position);
    button->was_hovered = sfFalse;
    button->on_click = NULL;
    button->on_hover = NULL;
    button->on_leave = NULL;
}

// create button
button_t *button_create(char *text, char *font, sfColor color)
{
    button_t *button = malloc(sizeof(button_t));

    if (button == NULL)
        return (NULL);
    button->font = sfFont_createFromFile(font);
    button->text = sfText_create();
    button->shape = sfRectangleShape_create();
    if (!button->shape || !button->text || !button->font)
        return (NULL);
    button_init(button, text, font, color);
    return (button);
}

// add button to menu
void add_button(menu_t *menu, char *text, char *font, sfColor color)
{
    button_t **arr = malloc(sizeof(button_t *) * (menu->button_count + 1));
    button_t *button = button_create(text, font, color);

    if (!arr || !button)
        return;
    for (int i = 0; i < menu->button_count; ++i)
        arr[i] = menu->buttons[i];
    arr[menu->button_count] = button;
    menu->button_count += 1;
    if (menu->buttons)
        free(menu->buttons);
    menu->buttons = arr;
}