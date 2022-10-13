/*
** EPITECH PROJECT, 2020
** game scene
** File description:
** rpg
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "game_loop.h"
#include "stdio.h"
#include "battle.h"
#include "function.h"
#include "engine.h"

void move_npc(entity_t *entity);

void game_scene_map(global_t *global)
{
    sfVector2f pos;

    while (sfRenderWindow_isOpen(global->window.window)
    && global->sprite_sheet.display_inv == 0
    && global->sprite_sheet.display_pause == 0 &&
    global->window.rtn_menu == 1 && global->display_battle == 0) {
        pos = get_tile_from_pos(sfSprite_getPosition(global->player.sprite));
        if (global->end_zone == 1 && pos.y < 6) {
        global->window.rtn_menu = -6;
        }
        manage_events(global);
        manage_camera(global);
        manage_place(global);
        display(global);
    }
}

void game_scene_inv(global_t *global)
{
    while (sfRenderWindow_isOpen(global->window.window)
    && global->sprite_sheet.display_inv == 1
    && global->sprite_sheet.display_pause == 0 && global->window.rtn_menu == 1
    && global->display_battle == 0)
        display_ui(global);
}

void game_scene_pause(global_t *global)
{
    while (sfRenderWindow_isOpen(global->window.window)
    && global->sprite_sheet.display_inv == 0
    && global->sprite_sheet.display_pause == 1 && global->window.rtn_menu == 1
    && global->display_battle == 0)
        display_pause(global);
}

void game_scene_battle(int i, global_t *global)
{
    int a = -1;

    while (sfRenderWindow_isOpen(global->window.window)
    && global->sprite_sheet.display_inv == 0
    && global->sprite_sheet.display_pause == 0 && global->window.rtn_menu == 1
    && global->display_battle == 1)
        a = battle(&global->player.pokemon, &global->enemy, global);
    if (a == 3 || a == 2) {
        add_object_inv(global, "level up", 1, "assets/images/tc.png");
        move_npc(global->entity_tmp);
    }
    global->player.pokemon.life = global->player.pokemon.base_life;
}

void game_scene_final(global_t *global)
{
    if (global->window.rtn_menu == -6) {
        global->window.rtn_menu = -4;
        outro(global);
    }
}