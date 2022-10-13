/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_collision
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "engine.h"
#include "stdio.h"
#include "entity.h"

void collide_neighbor_tile_hor(global_t *global, int y, int x)
{
    float rotation = sfSprite_getRotation(global->player.sprite);
    entity_t *e = get_entity_at_pos(global, (sfVector2i) {.x = x + 1, .y = y});
    entity_t *e2 = get_entity_at_pos(global, (sfVector2i) {.x = x-1, .y = y});

    if ((global->place->tiles[y][x + 1].walkable == 0 || e)
    && global->player.pos.x > (float)(x + 1) * 64 - 32)
        global->player.pos.x = (float)(x + 1) * 64 - 32;
    if (x < global->place->size.x - 1
    && x > 0 && (global->place->tiles[y][x - 1].walkable == 0 || e2)
    && global->player.pos.x < (float)(x - 1) * 64 + 96) {
        global->player.pos.x = (float)(x - 1) * 64 + 96;
    }
}

void collide_neighbor_tile_vert(global_t *global, int y, int x)
{
    float rotation = sfSprite_getRotation(global->player.sprite);
    entity_t *e = get_entity_at_pos(global, (sfVector2i) {.x = x, .y = y + 1});
    entity_t *e2 = get_entity_at_pos(global, (sfVector2i) {.x = x, .y = y-1});

    if (y > 0 && (global->place->tiles[y - 1][x].walkable == 0 || e2)
    && global->player.pos.y < (float)(y - 1) * 64 + 96) {
        global->player.pos.y = (float)(y - 1) * 64 + 96;
    }
    if (y < global->place->size.y - 1 &&
    (global->place->tiles[y + 1][x].walkable == 0 || e)
    && global->player.pos.y > (float)(y + 1) * 64 - 32)
        global->player.pos.y = (float)(y + 1) * 64 - 32;
    collide_neighbor_tile_hor(global, y, x);
}

void player_collision(global_t *global)
{
    sfVector2f tile_pos =  get_tile_from_pos(global->player.pos);
    int is_on_bad_tile = 0;

    collide_neighbor_tile_vert(global, (int)tile_pos.y, (int)tile_pos.x);
    collide_neighbor_tile_hor(global, (int)tile_pos.y, (int)tile_pos.x);
}