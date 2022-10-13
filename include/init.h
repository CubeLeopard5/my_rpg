/*
** EPITECH PROJECT, 2020
** init
** File description:
** init
*/

#include "SFML/Graphics.h"
#include "struct.h"

#ifndef INIT_H_
#define INIT_H_

void init_environnement(global_t *global);
void init_game_menu(global_t *global);
void init_input(inputs_t *inputs);
void init_my_rect(global_t *global);
void init_music(global_t *global);
void init_player(player_t *player, global_t *global);
void init_sound(global_t *global);
void init_sprite_sheet(global_t *global);
void init_structs (global_t *global);
void init_time(my_time_t *time);
void init_this_sound(char *path, sfSound **sound, sfSoundBuffer **buffer);
void init_types(global_t *global);
void load_music(global_t *global, char *name);
sfSprite *init_this_sprite(char *path, global_t *global);
sfSprite *set_player_origin(sfSprite *sprite);
sfSprite *set_sprite_center_to_center(sfSprite *sprite);
pokehuman_t init_pokehuman(global_t *global, char *name, int level);

void menu_music_play_stop(global_t *global, int istop);
void map_music_play_stop(global_t *global, int istop);

#endif /* !INIT_H_ */
