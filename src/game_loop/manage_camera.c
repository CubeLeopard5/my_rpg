/*
** EPITECH PROJECT, 2020
** manage camera
** File description:
** manage_camera
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "function.h"
#include "game_loop.h"

sfVector2f correct_camera_pos(global_t *global, sfVector2f pos)
{
    sfVector2f size = sfView_getSize(global->main_camera);
    sfVector2f cur_center = sfView_getCenter(global->main_camera);

    if (pos.y  < size.y / 2)
        pos.y += size.y / 2 - pos.y;
    if (pos.x  < size.x / 2)
        pos.x += size.x / 2 - pos.x;
    if (cur_center.y + size.y / 2 > (float)global->place->size.y * 64) {
        pos.y = (float)global->place->size.y * 64 - size.y / 2;
    }
    if (cur_center.x + size.x / 2 > (float)global->place->size.x * 64) {
        pos.x = (float)global->place->size.x * 64 - size.x / 2;
    }
    return pos;
}

void manage_camera(global_t *global)
{
    sfVector2f player_pos;

    player_pos.x = global->player.pos.x;
    player_pos.y = global->player.pos.y;
    sfView_setCenter(global->main_camera, player_pos);
    player_pos = correct_camera_pos(global, player_pos);
    sfView_setCenter(global->main_camera, player_pos);
    sfRenderWindow_setView(global->window.window, global->main_camera);
}