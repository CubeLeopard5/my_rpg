/*
** EPITECH PROJECT, 2019
** library.h
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
#include "scenes/menu.h"

#ifndef CHAR_CREATE_H_
#define CHAR_CREATE_H_

typedef struct char_create_s char_create_t;

struct char_create_s {
    char *player;
    int plyr_char_pos;
    int a;
    sfFont *fonty;
    sfRectangleShape *hover;
    sfSprite *button_start;
    sfSprite *button_return;
    sfSprite *pikapikacreate;
    sfSprite *textinput;
    sfSprite *backgr;
    sfText *keyputs;
};

//int create_perso(global_t *global);
void events(sfEvent event, sfRenderWindow *window, char_create_t *char_create);
void init_disp_char_creation_buttons(char_create_t *char_create,
sfRenderWindow *window);
int my_str_event_is_validated(sfEvent event);
int text_tweaks(sfRenderWindow *win, sfEvent event, 
char_create_t *char_create);
void create_text_char_creation(char_create_t *char_create, sfVector2f textpos);
void finish_disp_char_creation(char_create_t *char_create,
sfRenderWindow *window, sfVector2f size);
void free_car_creation(char_create_t *char_create);
void pikapika_charcreation(char_create_t *char_create);

void event_howtoplay(menu_t *menu);
void menu_handle_click_howtplay(menu_t *menu, button_t *button);
void how_to_play(menu_t *menu);
void init_howtoplay(menu_t *menu);
void destroy_howtoplay(menu_t *menu);
void how_to_play_select(menu_t *menu);

#endif