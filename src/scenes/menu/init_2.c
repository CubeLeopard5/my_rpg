/*
** EPITECH PROJECT, 2020
** init number 2
** File description:
** RPG
*/

#include "scenes/menu.h"

void menu_init_buttons_2(menu_t *menu, int i,
sfVector2f position, sfColor hover_c[])
{
    button_action_t leave = &menu_handle_leave;

    menu->buttons[i]->on_leave = leave;
    button_set_position(menu->buttons[i], position);
    button_set_colors(menu->buttons[i], sfGreen, hover_c[i % 2 ? 1 : 0]);
}