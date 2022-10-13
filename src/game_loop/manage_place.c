/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** manage_place
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "game_loop.h"
#include "engine.h"
#include "map.h"

void manage_place(global_t *global)
{
    sfVector2i player_tile =
    vector_float_to_int(get_tile_from_pos(global->player.pos));
    for (int i = 0; global->place->zones[i] != NULL; i++) {
        if (global->place->zones[i]->local.x == player_tile.x &&
        global->place->zones[i]->local.y == player_tile.y) {
            switch_place(global, global->place->zones[i]->name, i);
        }
    }
}