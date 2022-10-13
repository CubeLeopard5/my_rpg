/*
** EPITECH PROJECT, 2020
** set pause menu
** File description:
** rpg
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "stdio.h"
#include "function.h"

void set_pause_menu_2(global_t *global, sfVector2f cur_center)
{
    for (int i = 0; i < 3; i++) {
        if (i == 0) {
            global->text_pause[i].pos.x = cur_center.x - 100;
            global->text_pause[i].pos.y = cur_center.y - 375 + i * 300;
        }
        if (i == 1) {
            global->text_pause[i].pos.x = cur_center.x - 180;
            global->text_pause[i].pos.y = cur_center.y - 375 + i * 300;
        }
        if (i == 2) {
            global->text_pause[i].pos.x = cur_center.x - 80;
            global->text_pause[i].pos.y = cur_center.y - 375 + i * 300;
        }
        sfText_setPosition(global->text_pause[i].text,
        global->text_pause[i].pos);
    }
}

void set_pause_menu(global_t *global)
{
    sfVector2f cur_center = sfView_getCenter(global->main_camera);

    for (int i = 0; i < 3; i++) {
        global->button_pause[i].pos.x = cur_center.x - 400;
        global->button_pause[i].pos.y = cur_center.y - 400 + i * 300;
        sfRectangleShape_setPosition(global->button_pause[i].button,
        global->button_pause[i].pos);
    }
    set_pause_menu_2(global, cur_center);
}