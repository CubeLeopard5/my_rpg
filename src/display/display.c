/*
** EPITECH PROJECT, 2020
** display
** File description:
** display
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "game_loop.h"
#include "function.h"
#include "particles.h"

void display_player(global_t *global)
{
    static float a = 0.0;
    static int i = 0;

    sfSprite_setPosition(global->player.sprite, global->player.pos);
    if (compare_time(global->time.clock, &a, 200.0) == 1) {
        move_rect_player(global, i, global->player.animation,
        global->player.sprite);
        i++;
        if (i > 3)
            i = 0;
    }
    sfRenderWindow_drawSprite
    (global->window.window, global->player.sprite, NULL);
}

void display(global_t *global)
{
    sfRenderWindow_clear(global->window.window, sfBlack);
    display_map(global);
    display_entities(global);
    display_player(global);
    meteo_display(global);
    sfRenderWindow_display(global->window.window);
}