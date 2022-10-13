/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** intro
*/

#include "SFML/Graphics.h"
#include "SFML/Audio.h"
#include "struct.h"

#ifndef INTRO_H_
#define INTRO_H_

sfText *change_text(sfText *text, char *str);
void init_intro(global_t *global);
void intro(global_t *global);
int intro_events(global_t *global);
void intro_steps(global_t *global, int *intro_state, float *time_float);
sfText *set_text_center_to_center(sfText *text);
sfSprite *turn_pika(sfSprite *sprite, int dir);
void outro(global_t *global);
void outro_steps(global_t *global, int *intro_state, float *time_float);


#endif /* !INTRO_H_ */
