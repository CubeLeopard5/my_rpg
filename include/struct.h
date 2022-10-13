/*
** EPITECH PROJECT, 2020
** structures
** File description:
** rpg
*/

#include "struct_place.h"
#include "struct_ui.h"
#include "struct_time.h"
#include "struct_poke_human.h"
#include "struct_entity.h"
#include "struct_sound.h"
#include "npc.h"

#ifndef STRUCT_H
#define STRUCT_H

typedef struct outro_t
{
    sfSprite *background;
    sfText *text;
    sfFont *font;
    sfSprite *otaria;
}outro_t;

typedef struct intro_t
{
    sfSprite *background;
    sfSprite *Pickachu;
    sfMusic *music;
    sfText *text;
    sfFont *font;
}intro_t;

typedef struct inputs_t
{
    sfKeyCode up;
    sfKeyCode down;
    sfKeyCode left;
    sfKeyCode right;

}inputs_t;

typedef struct hitbox_t
{
    int left;
    int right;
    int top;
    int bottom;
}hitbox_t;

typedef struct object_effect_t
{
}object_effect_t;

typedef struct player_t
{
    float balise_mv;
    float delay_mv;
    sfVector2f pos;
    sfSprite *sprite;
    float speed;
    sfIntRect rect;
    int animation;
    int atk_choice;
    pokehuman_t pokemon;
}player_t;

typedef struct window_t
{
    sfRenderWindow *window;
    sfEvent event;
    int rtn_menu;
}window_t;

typedef struct image_t
{
    sfTexture *battle_tex;
    sfSprite *battle_spr;
    sfVector2f pos;
}image_t;

typedef struct button_ui_t
{
    sfRectangleShape *button;
    sfVector2f pos;
    sfVector2f size;
}button_ui_t;

typedef struct button_pause_t
{
    sfRectangleShape *button;
    sfVector2f pos;
    sfVector2f size;
}button_pause_t;

typedef struct text_pause_t
{
    sfText *text;
    sfFont *font;
    sfVector2f pos;
}text_pause_t;

typedef struct sprite_sheet_t
{
    int sp_sheet_count;
    int tx_sheet_count;
    sfSprite **sprite;
    sfTexture **texture;
    sfIntRect rect;
    sfVector2f *pos;
    sfSprite **sprite_inv;
    sfTexture **texture_inv;
    sfVector2f *scale_inv;
    sfVector2f *pos_inv;
    int display_inv;
    int display_pause;
}sprite_sheet_t;

typedef struct button_battle_t
{
    sfRectangleShape *button;
    sfVector2f pos;
    sfVector2f size;
    sfText *text;
    sfVector2f txt_pos;
}button_battle_t;

typedef struct object_t
{
    char *name;
    int id;
    sfSprite *spr;
    sfTexture *tx;
    sfVector2f pos;
}object_t;

typedef struct text_stat_t
{
    sfText *text;
    sfFont *font;
    sfVector2f pos;
}text_stat_t;

typedef struct global_t
{
    button_ui_t *button_ui;
    button_pause_t *button_pause;
    button_battle_t *button_battle;
    int display_battle;
    int animation_battle;
    int pokemon_turn;
    entity_t *entity_tmp;
    text_pause_t *text_pause;
    object_t *object;
    text_stat_t *text_stat;
    image_t *image;
    window_t window;
    tile_t tile;
    player_t player;
    object_effect_t object_effect;
    sfSprite ***env_spr;
    sprite_sheet_t sprite_sheet;
    inputs_t input;
    place_t *place;
    sfView *main_camera;
    int camera_zoom;
    attack_t **attacks;
    my_time_t time;
    pokehuman_t enemy;
    entity_t **entities;
    int **type_chart;
    sfTexture **texture_array;
    int text_nbr;
    intro_t intro;
    outro_t outro;
    my_sound_t sound;
    npc_array_t npc;
    sfMusic *music;
    int end_zone;
    int meteo_rand;
}global_t;

#endif
