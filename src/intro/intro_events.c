/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** intro_events
*/

#include "intro.h"
#include "SFML/Graphics.h"

int intro_events(global_t *global)
{
    while (sfRenderWindow_pollEvent(global->window.window,
    &global->window.event))
    {
        if (global->window.event.type == sfEvtClosed)
            sfRenderWindow_close(global->window.window);
        if (global->window.event.type == sfEvtKeyPressed) {
            return (1);
        }
    }
    return (0);
}