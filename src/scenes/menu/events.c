/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** events.c
*/

#include "scenes/menu.h"

void menu_event_click(menu_t *menu, sfEvent *e)
{
    sfVector2f mouse_pos = {.x = e->mouseButton.x, .y = e->mouseButton.y};

    for (int i = 0; i < menu->button_count; ++i) {
        if (button_pointed(menu->buttons[i], mouse_pos)) {
            menu->buttons[i]->on_click(menu, menu->buttons[i]);
            return;
        }
    }
}

void menu_event_hover(menu_t *menu, sfEvent *e)
{
    sfVector2f mouse_pos = {.x = e->mouseMove.x, .y = e->mouseMove.y};

    for (int i = 0; i < menu->button_count; ++i) {
        if (button_pointed(menu->buttons[i], mouse_pos)) {
            menu->buttons[i]->on_hover(menu, menu->buttons[i]);
        } else {
            menu->buttons[i]->on_leave(menu, menu->buttons[i]);
        }
    }
}

int menu_handle_event(menu_t *menu, sfEvent *e)
{
    switch (e->type) {
        case sfEvtClosed:
            sfRenderWindow_close(menu->window);
            menu->user_choice = 4;
            break;
        case sfEvtMouseButtonPressed: menu_event_click(menu, e);
            break;
        case sfEvtMouseMoved: menu_event_hover(menu, e);
            break;
        default: break;
    }
    return 0;
}

int menu_handle_events(menu_t *menu)
{
    sfEvent e;
    int r = 0;

    while (sfRenderWindow_pollEvent(menu->window, &e) && r == 0)
        r = menu_handle_event(menu, &e);
    return r;
}