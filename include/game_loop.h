/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_loop
*/

#include "SFML/Graphics.h"
#include "struct.h"

#ifndef GAME_LOOP_H_
#define GAME_LOOP_H_

void dezoom_camera(global_t *global);
void display(global_t *global);
void display_map(global_t *global);
void display_entities(global_t *global);
int game_loop(global_t *global);
void how_to_play(menu_t *menu);
void player_collision(global_t *global);
void load_npc(char *name, global_t *global);
void manage_camera(global_t *global);
void manage_events(global_t *global);
void manage_inputs(global_t *global, sfKeyCode input);
void manage_place(global_t *global);
void move_player_up(global_t *global);
void move_player_down(global_t *global);
void move_player_left(global_t *global);
void move_player_right(global_t *global);
void zoom_camera(global_t *global);

#endif /* !GAME_LOOP_H_ */
