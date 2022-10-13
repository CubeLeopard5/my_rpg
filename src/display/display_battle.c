/*
** EPITECH PROJECT, 2020
** display battle
** File description:
** rpg
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "stdio.h"
#include "function.h"

void battle_functions(global_t *global, int i)
{
    if (i == 0)
        global->player.atk_choice = 0;
    if (i == 1)
        global->player.atk_choice = 1;
    if (i == 2)
        global->player.atk_choice = 2;
    if (i == 3)
        global->player.atk_choice = 3;
}

void manage_battle_input(global_t *global, int x, int y)
{
    sfVector2f rec = sfView_getCenter(global->main_camera);

    if (global->window.event.type == sfEvtMouseButtonPressed) {
        y = y + rec.y - 535;
        x = x + rec.x - 955;
        for (int i = 0; i < 4; i++) {
            if (x <= global->button_battle[i].pos.x +
            global->button_battle[i].size.x && x >=
            global->button_battle[i].pos.x
            && y <= global->button_battle[i].pos.y +
            global->button_battle[i].size.y && y >=
            global->button_battle[i].pos.y)
                battle_functions(global, i);
        }
    }
}

void event_battle(global_t *global)
{
    sfVector2i pos;

    while (sfRenderWindow_pollEvent(global->window.window,
    &global->window.event)) {
        if (global->window.event.type == sfEvtClosed)
            sfRenderWindow_close(global->window.window);
        if (global->window.event.type == sfEvtKeyPressed ||
        global->window.event.type == sfEvtMouseButtonPressed) {
            pos = sfMouse_getPositionRenderWindow(global->window.window);
            manage_battle_input(global, pos.x, pos.y);
        }
    }
}

void display_battle_elements(pokehuman_t *a, pokehuman_t *b, global_t *global)
{
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawSprite(global->window.window,
        global->image[i].battle_spr, NULL);
    sfRenderWindow_drawSprite(global->window.window, a->sprite, NULL);
    sfRenderWindow_drawSprite(global->window.window, b->sprite, NULL);
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawRectangleShape(global->window.window,
        global->button_battle[i].button, NULL);
        sfRenderWindow_drawText(global->window.window,
        global->button_battle[i].text, NULL);
    }
    sfRenderWindow_display(global->window.window);
}

void display_battle(pokehuman_t *a, pokehuman_t *b, global_t *global, int i)
{
    if (i == 1) {
        set_battle_menu(a, b, global);
        display_battle_elements(a, b, global);
        event_battle(global);
    }
    else if (i == 2) {
        set_battle_menu(b, a, global);
        display_battle_elements(b, a, global);
        event_battle(global);
    }
}