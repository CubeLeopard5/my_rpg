/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_tile_from_pos
*/

#include "SFML/Graphics.h"

sfVector2f get_tile_from_pos(sfVector2f pos)
{
    sfVector2f tile;

    tile.x = 0;
    tile.y = 0;
    for (int i = 0; pos.x > 64; pos.x = pos.x - 64) {
        tile.x += 1;
    }
    for (int i = 0; pos.y > 64; pos.y = pos.y - 64) {
        tile.y += 1;
    }
    return (tile);
}