/*
** EPITECH PROJECT, 2020
** rect of player
** File description:
** rpg
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "init.h"

void move_rect_player_4(global_t *global, int face, int line)
{
    if (face == 0 && line == 3) {
        global->player.rect.top = 384;
        global->player.rect.left = 0;
    }
    if (face == 1 && line == 3) {
        global->player.rect.top = 384;
        global->player.rect.left = 128;
    }
    if (face == 2 && line == 3) {
        global->player.rect.top = 384;
        global->player.rect.left = 256;
    }
    if (face == 3 && line == 3) {
        global->player.rect.top = 384;
        global->player.rect.left = 384;
    }
}

void move_rect_player_3(global_t *global, int face, int line)
{
    if (face == 0 && line == 2) {
        global->player.rect.top = 256;
        global->player.rect.left = 0;
    }
    if (face == 1 && line == 2) {
        global->player.rect.top = 256;
        global->player.rect.left = 128;
    }
    if (face == 2 && line == 2) {
        global->player.rect.top = 256;
        global->player.rect.left = 256;
    }
    if (face == 3 && line == 2) {
        global->player.rect.top = 256;
        global->player.rect.left = 384;
    }
    move_rect_player_4(global, face, line);
}

void move_rect_player_2(global_t *global, int face, int line)
{
    if (face == 0 && line == 1) {
        global->player.rect.top = 128;
        global->player.rect.left = 0;
    }
    if (face == 1 && line == 1) {
        global->player.rect.top = 128;
        global->player.rect.left = 128;
    }
    if (face == 2 && line == 1) {
        global->player.rect.top = 128;
        global->player.rect.left = 256;
    }
    if (face == 3 && line == 1) {
        global->player.rect.top = 128;
        global->player.rect.left = 384;
    }
    move_rect_player_3(global, face, line);
}

void move_rect_player(global_t *global, int face, int line, sfSprite *sprite)
{
    if (face == 0 && line == 0) {
        global->player.rect.top = 0;
        global->player.rect.left = 0;
    }
    if (face == 1 && line == 0) {
        global->player.rect.top = 0;
        global->player.rect.left = 128;
    }
    if (face == 2 && line == 0) {
        global->player.rect.top = 0;
        global->player.rect.left = 256;
    }
    if (face == 3 && line == 0) {
        global->player.rect.top = 0;
        global->player.rect.left = 384;
    }
    move_rect_player_2(global, face, line);
    sfSprite_setTextureRect(sprite, global->player.rect);
}

void init_rect_player(global_t *global)
{
    global->player.rect.top = 0;
    global->player.rect.left = 0;
    global->player.rect.width = 128;
    global->player.rect.height = 128;
}