/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** scene.c
*/

#include "scenes/menu.h"

int menu_scene(menu_t *menu)
{
    menu_init(menu);
    menu->user_choice = 0;
    while (sfRenderWindow_isOpen(menu->window) && menu->user_choice == 0) {
        menu_rendering(menu);
        menu_handle_events(menu);
    }
    menu_destroy(menu);
    return (menu->user_choice);
}