/*
** EPITECH PROJECT, 2020
** render settings
** File description:
** rpg
*/

#include "scenes/menu.h"

void settings_rendering(menu_t *menu)
{
    sfRenderWindow_clear(menu->window, sfBlack);
    sfRenderWindow_drawSprite(menu->window, menu->sprites[0], NULL);
    for (int i = 0; i < menu->button_count; ++i) {
        button_render(menu->window, menu->buttons[i]);
    }
    for (int i = 0; i < menu->settings.text_count; ++i) {
        sfRenderWindow_drawText(menu->window, menu->settings.text[i], NULL);
    }
    sfRenderWindow_display(menu->window);
}