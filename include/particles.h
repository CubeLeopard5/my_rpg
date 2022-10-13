/*
** EPITECH PROJECT, 2019
** particles.h
** File description:
** this is mine library
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "struct.h"

#ifndef PARTICLES_H_
#define PARTICLES_H_

void advanced_particle_spray(sfVector2f position, sfColor color,
sfRenderWindow *win, int size);
void advanced_particle_init(sfVector2f *position_array,
sfVector2f position, int *velocity, int size);
void advanced_particle_daw_base(sfVector2f *position_array,
sfRenderWindow *win, int *velocity, sfRectangleShape *particle);
void advanced_particle_left_up(sfVector2f *position_array,
sfRenderWindow *win, int *velocity, sfRectangleShape *particle);
void advanced_particle_righ_up(sfVector2f *position_array,
sfRenderWindow *win, int *velocity, sfRectangleShape *particle);
void advanced_particle_left_dn(sfVector2f *position_array,
sfRenderWindow *win, int *velocity, sfRectangleShape *particle);
void advanced_particle_righ_dn(sfVector2f *position_array,
sfRenderWindow *win, int *velocity, sfRectangleShape *particle);
void attack_move_up_to_down_destroy(sfSprite *sprite, sfRenderWindow *win,
sfClock *clocking, sfVector2f refer);
void attack_move_down_to_up_destroy(sfSprite *sprite, sfRenderWindow *win,
sfClock *clocking, sfVector2f refer);
void bubble_text_draw(sfVector2f positions, sfText *texty, sfRenderWindow *win,
int speed);
void particle_spray(sfVector2f position, sfColor color,
sfRenderWindow *win, int size);
void draw_particle_system_random_angle(sfVector2f position, sfRectangleShape
*particle, sfRenderWindow *win, int i);
void draw_particle_system_fixed_angle(sfVector2f position, sfRectangleShape
*particle, sfRenderWindow *win, int i);
void draw_particle_system_fixed_angle_next(sfVector2f position,
sfRectangleShape *particle, sfRenderWindow *win, int i);
int anime_scale_grow(sfSprite *sprite, sfRenderWindow *win, int toscale,
int speed);
int anime_scale_resize(sfSprite *sprite, sfRenderWindow *win, int toscale,
int speed);
void attack_move_left_to_right_destroy(sfSprite *sprite, sfRenderWindow *win,
sfClock *clocking, sfVector2f refer);
void attack_move_right_to_left_destroy(sfSprite *sprite, sfRenderWindow *win,
sfClock *clocking, sfVector2f refer);
sfText *init_text_atk(pokehuman_t *attacker, attack_t *attack);
sfVector2f init_pos_atk(global_t *global);
void bubble_text_draw_big(sfVector2f positions, sfText *texty,
sfRenderWindow *win, int speed);
void battle_music_play_stop(global_t *global, int istop);
void make_it_rain_or_snow(global_t *global, int issnow, int speed,
int is_init_or_reset);
void let_it_go_rain(global_t *global, int speed,
int *velocity, sfVector2f *position_array);
void let_it_go_snow(global_t *global, int speed,
int *velocity, sfVector2f *p_a);
void let_it_go_circle_tweaks(int wichone, global_t *global, sfVector2f *p_a, 
sfCircleShape *circle);
void meteo_display(global_t *global);
void free_music(global_t *global);
void bubble_text_sound(sfVector2f positions, sfText *texty,
sfRectangleShape *hover);
void let_it_go_free(sfVector2f *position_array, int *velocity);
void music_sound_reduceing(global_t *global);

#endif