/*
** EPITECH PROJECT, 2020
** resize window
** File description:
** rpg
*/

#include "scenes/menu.h"
#include "minilib.h"

void settings_resize_window_800x600(menu_t *menu, button_t *button)
{
    sfVector2u window_size = {.x = 800, .y = 600};

    sfRenderWindow_setSize(menu->window, window_size);
    menu->window_size = window_size;
}

void settings_resize_window_1920x1080(menu_t *menu, button_t *button)
{
    sfVector2u window_size = {.x = 1920, .y = 1080};

    sfRenderWindow_setSize(menu->window, window_size);
    menu->window_size = window_size;
}