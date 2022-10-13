/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** menu.h
*/

#ifndef __SCENE_MENU_H__
#define __SCENE_MENU_H__

#include "engine.h"

// scene.c
int menu_scene(menu_t *menu);

// rendering.c
void menu_rendering(menu_t *menu);

// init.c
void menu_init(menu_t *menu);
void menu_init_buttons_2(menu_t *menu, int i,
sfVector2f position, sfColor hover_c[]);
void menu_destroy(menu_t *menu);

// events.c
int menu_handle_events(menu_t *menu);

// event_handler.c
void the_menu(menu_t *menu, button_t *button);
void menu_handle_click_play(menu_t *menu, button_t *button);
void menu_handle_click_settings(menu_t *menu, button_t *button);
void menu_handle_click_howtplay(menu_t *menu, button_t *button);
void menu_handle_click_quit(menu_t *menu, button_t *button);
void menu_handle_hover(menu_t *menu, button_t *button);
void menu_handle_leave(menu_t *menu, button_t *button);

//init_settings.c
void init_settings(menu_t *menu);
void settings_destroy(menu_t *menu);

//event_settings.c
void settings_menu_vol_plus(menu_t *menu, button_t *button);
void settings_menu_vol_minus(menu_t *menu, button_t *button);
void settings_sound_vol_plus(menu_t *menu, button_t *button);
void settings_sound_vol_minus(menu_t *menu, button_t *button);

//settings_rendering.c
void settings_rendering(menu_t *menu);

//settings_init_buttons.c
void settings_init_buttons(menu_t *menu);

//menu_settings.c
void menu_settings(menu_t *menu);

//event_resize.c
void settings_resize_window_800x600(menu_t *menu, button_t *button);
void settings_resize_window_1920x1080(menu_t *menu, button_t *button);

#endif