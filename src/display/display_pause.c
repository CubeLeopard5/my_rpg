/*
** EPITECH PROJECT, 2020
** pause menu
** File description:
** rpg
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "stdio.h"
#include "function.h"

void pause_functions(global_t *global, int i)
{
    if (i == 0)
        manage_display_pause(global);
    if (i == 1)
        global->window.rtn_menu = -1;
    if (i == 2)
        global->window.rtn_menu = -4;
}

void manage_pause_input(global_t *global, int x, int y)
{
    sfVector2f rec = sfView_getCenter(global->main_camera);

    if (global->window.event.key.code == sfKeyEscape)
        manage_display_pause(global);
    if (global->window.event.type == sfEvtMouseButtonPressed) {
        y = y + rec.y - 535;
        x = x + rec.x - 955;
        for (int i = 0; i < 3; i++) {
            if (x <= global->button_pause[i].pos.x +
            global->button_pause[i].size.x && x >=
            global->button_pause[i].pos.x && y <=
            global->button_pause[i].pos.y +
            global->button_pause[i].size.y && y >=
            global->button_pause[i].pos.y)
                pause_functions(global, i);
        }
    }
}

void event_pause(global_t *global)
{
    sfVector2i pos;

    while (sfRenderWindow_pollEvent(global->window.window,
    &global->window.event)) {
        if (global->window.event.type == sfEvtClosed)
            sfRenderWindow_close(global->window.window);
        if (global->window.event.type == sfEvtKeyPressed ||
        global->window.event.type == sfEvtMouseButtonPressed) {
            pos = sfMouse_getPositionRenderWindow(global->window.window);
            manage_pause_input(global, pos.x, pos.y);
        }
    }
}

void display_pause(global_t *global)
{
    set_pause_menu(global);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawRectangleShape(global->window.window,
        global->button_pause[i].button, NULL);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawText(global->window.window,
        global->text_pause[i].text, NULL);
    sfRenderWindow_display(global->window.window);
    event_pause(global);
}