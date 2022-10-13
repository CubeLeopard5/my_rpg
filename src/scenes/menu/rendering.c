/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** rendering.c
*/

#include "scenes/menu.h"

void menu_rendering(menu_t *menu)
{
    sfRenderWindow_clear(menu->window, sfBlack);
    for (int i = 0; i < 1; i++)
        sfRenderWindow_drawSprite
        (menu->window, menu->sprites[i], NULL);
    for (int i = 0; i < menu->button_count; ++i) {
        button_render(menu->window, menu->buttons[i]);
    }
    sfRenderWindow_display(menu->window);
}