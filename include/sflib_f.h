/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** 3d.h
*/

#ifndef _SFLIB_F
#define _SFLIB_F

#include <stddef.h>
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

//Check if the mouse is inside a sprite
//return 1 if true
int is_inside_here(sfSprite *sprite, sfRenderWindow *win);

//Draw a button sprite in parameter and a hover (if mouse is inside) 
//with the color you define
void button_draw_classic(sfSprite *sprite, sfRenderWindow *win,
sfColor colour, sfRectangleShape *hover_b);
void bubble_txt_clock_big(sfText *texty, sfRenderWindow *win,
sfRectangleShape *hover, char *textyno);
void bubble_text_3_big(const char *base_text, char *textyno, int is_new_text);
void bubble_txt_clock(sfText *texty, sfRenderWindow *win,
sfRectangleShape *hover, char *textyno);
int bubble_text_3(const char *base_text, char *textyno, int is_new_text);

//Scaling parameters for better scaling in function of windo size
// type = 0 -> resize the sprite while window.x & window.y > sprite size
// type = 1 -> resize the sprite while window.x OR window.y > sprite size
// type = 2 -> resize the sprite while 
//window.x > sprite_size.x & window.y > sprite_size.y (translation)
float scalinator(sfSprite *sprite, int type, sfRenderWindow *win);
void scalinator_2(sfSprite *sprite, int type, sfRenderWindow *win);
void scalinator_3(sfSprite *sprite, int type, sfRenderWindow *win);

#endif