/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** move_sprite
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "function.h"
#include "game_loop.h"

void move_player_up(global_t *global)
{
    if (compare_time(global->time.clock, &global->player.balise_mv,
    global->player.delay_mv) == 1) {
        global->player.animation = 3;
        global->player.pos.y -= global->player.speed;
    }
    player_collision(global);
}

void move_player_down(global_t *global)
{
    if (compare_time(global->time.clock, &global->player.balise_mv,
    global->player.delay_mv) == 1) {
        global->player.animation = 0;
        global->player.pos.y += global->player.speed;
    }
    player_collision(global);
}

void move_player_left(global_t *global)
{
    if (compare_time(global->time.clock, &global->player.balise_mv,
    global->player.delay_mv) == 1) {
        global->player.animation = 1;
        global->player.pos.x -= global->player.speed;
    }
    player_collision(global);
}

void move_player_right(global_t *global)
{
    if (compare_time(global->time.clock, &global->player.balise_mv,
    global->player.delay_mv) == 1) {
        global->player.animation = 2;
        global->player.pos.x += global->player.speed;
    }
    player_collision(global);
}
