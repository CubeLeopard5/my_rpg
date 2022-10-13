/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** mange_events
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "game_loop.h"

void manage_events(global_t *global)
{
    while (sfRenderWindow_pollEvent(global->window.window,
    &global->window.event))
    {
        if (global->window.event.type == sfEvtClosed)
            sfRenderWindow_close(global->window.window);
        if (global->window.event.type == sfEvtKeyPressed)
            manage_inputs(global, global->window.event.key.code);
    }
}