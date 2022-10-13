/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** event_handler.c
*/

#include "scenes/menu.h"
#include "minilib.h"

void menu_handle_click_play(menu_t *menu, button_t *button)
{
    menu->user_choice = 1;
}

void menu_handle_click_settings(menu_t *menu, button_t *button)
{
    menu->user_choice = 2;
}

void menu_handle_click_quit(menu_t *menu, button_t *button)
{
    const char *text = sfText_getString(button->text);

    sfRenderWindow_close(menu->window);
    menu->user_choice = 4;
}

void menu_handle_hover(menu_t *menu, button_t *button)
{
    if (!button->was_hovered) {
        button->was_hovered = true;
        button_set_color(button, button->hover_color);
    }
}

void menu_handle_leave(menu_t *menu, button_t *button)
{
    if (button->was_hovered) {
        button->was_hovered = false;
        button_set_color(button, button->button_color);
    }
}