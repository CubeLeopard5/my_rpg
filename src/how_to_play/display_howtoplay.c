/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display_howtoplay.c
*/

#include "scenes/menu.h"
#include "minilib.h"
#include "char_create.h"

void event_howtoplay(menu_t *menu)
{
    sfEvent e;

    while (sfRenderWindow_pollEvent(menu->window, &e)) {
        if (e.type == sfEvtKeyPressed) {
            menu->howtoplay.htp_state++;
            if (menu->howtoplay.htp_state == 3) {
                menu->user_choice = 0;
            }
        }
    }
}

void menu_handle_click_howtplay(menu_t *menu, button_t *button)
{
    menu->user_choice = 3;
}

void how_to_play_select(menu_t *menu)
{
    if (menu->howtoplay.htp_state == 0)
        sfRenderWindow_drawSprite(menu->window, menu->howtoplay.htp_bckgr,
        NULL);
    if (menu->howtoplay.htp_state == 1)
        sfRenderWindow_drawSprite(menu->window, menu->howtoplay.htp_bckgr_2,
        NULL);
    if (menu->howtoplay.htp_state == 2)
        sfRenderWindow_drawSprite(menu->window, menu->howtoplay.htp_bckgr_3,
        NULL);
}

void how_to_play(menu_t *menu)
{
    init_howtoplay(menu);
    while (sfRenderWindow_isOpen(menu->window) && menu->user_choice == 3) {
        how_to_play_select(menu);
        event_howtoplay(menu);
        sfRenderWindow_display(menu->window);
    }
    destroy_howtoplay(menu);
}