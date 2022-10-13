/*
** EPITECH PROJECT, 2020
** manage inputs
** File description:
** manage_inputs
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "game_loop.h"
#include "entity.h"
#include "init.h"
#include "particles.h"

void manage_display_battle(global_t *global)
{
    dezoom_camera(global);
    dezoom_camera(global);
    if (global->display_battle == 0) {
        sfSound_play(global->sound.ambiant.bstart);
        global->display_battle = 1;
        sfMusic_stop(global->music);
        battle_music_play_stop(global, 0);
    }
    else if (global->display_battle == 1) {
        global->display_battle = 0;
        battle_music_play_stop(global, 1);
        sfMusic_play(global->music);
    }
}

void manage_display_pause(global_t *global)
{
    dezoom_camera(global);
    dezoom_camera(global);
    if (global->sprite_sheet.display_pause == 0) {
        global->sprite_sheet.display_pause = 1;
        sfMusic_stop(global->music);
        menu_music_play_stop(global, 0);
    }
    else if (global->sprite_sheet.display_pause == 1) {
        global->sprite_sheet.display_pause = 0;
        sfMusic_play(global->music);
        menu_music_play_stop(global, 1);
    }
}

void manage_display_inv(global_t *global)
{
    dezoom_camera(global);
    dezoom_camera(global);
    if (global->sprite_sheet.display_inv == 0)
        global->sprite_sheet.display_inv = 1;
    else if (global->sprite_sheet.display_inv == 1)
        global->sprite_sheet.display_inv = 0;
}

void manage_inputs2(global_t *global, sfKeyCode input)
{
    switch (input) {
        case sfKeyUp: zoom_camera(global);
            break;
        case sfKeyDown: dezoom_camera(global);
            break;
        default:
            break;
    }
}

void manage_inputs(global_t *global, sfKeyCode input)
{
    switch (input) {
        case sfKeyZ: move_player_up(global);
            break;
        case sfKeyS: move_player_down(global);
            break;
        case sfKeyD: move_player_right(global);
            break;
        case sfKeyQ: move_player_left(global);
            break;
        case sfKeyX: manage_display_inv(global);
            break;
        case sfKeyB: global->window.rtn_menu = -6;
            break;
        case sfKeyEscape: manage_display_pause(global);
            break;
        case sfKeyEnter: handle_entity_interaction(global);
            break;
        default: manage_inputs2(global, input);
            break;
    }
}
