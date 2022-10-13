/*
** EPITECH PROJECT, 2020
** menu_settings
** File description:
** rpg
*/

#include "scenes/menu.h"

void menu_settings(menu_t *menu)
{
    init_settings(menu);
    while (sfRenderWindow_isOpen(menu->window) && menu->user_choice == 2) {
        settings_rendering(menu);
        menu_handle_events(menu);
    }
    settings_destroy(menu);
}