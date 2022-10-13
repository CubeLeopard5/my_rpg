/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** engine.h
*/

#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "function.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stddef.h>

// window.c
sfRenderWindow *get_window(sfVector2u *size, sfBool fullscreen, char *title,
    int framerate);
// buttons
button_t *button_create(char *text, char *font, sfColor color);
void button_destroy(button_t *button);
void add_button(menu_t *menu, char *text, char *font, sfColor color);
sfBool button_pointed(button_t *button, sfVector2f mouse_click);
void button_set_position(button_t *button, sfVector2f position);
void button_set_color(button_t *button, sfColor button_color);
void button_set_colors(button_t *button, sfColor button_color,
    sfColor hover_color);
void button_set_text(button_t *button, char *text);
void button_render(sfRenderWindow *window, button_t *button);
sfVector2f get_tile_from_pos(sfVector2f pos);
sfVector2i vector_float_to_int(sfVector2f vec_float);
sfVector2f vector_int_to_float(sfVector2i vec_int);
void outro(global_t *global);

#endif