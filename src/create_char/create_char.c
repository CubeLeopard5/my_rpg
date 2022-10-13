/*
** EPITECH PROJECT, 2020
** game loop
** File description:
** the game main loop
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "function.h"
#include "stdio.h"
#include "sflib_f.h"
#include "char_create.h"
#include <library.h>

void display_char_creation(char_create_t *char_create, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, char_create->backgr, NULL);
    sfRenderWindow_drawSprite(window, char_create->pikapikacreate, NULL);
    button_draw_classic(char_create->button_start, window, sfBlack,
    char_create->hover);
    button_draw_classic(char_create->button_return, window, sfBlack,
    char_create->hover);
    button_draw_classic(char_create->textinput, window, sfBlack,
    char_create->hover);
    sfRenderWindow_drawText(window, char_create->keyputs, NULL);
}

void init_disp_char_creation(char_create_t *char_create,
sfRenderWindow *window)
{
    sfTexture *backgr_txture;
    sfTexture *keyputs_txture;
    sfVector2f keyputs_pos = {700, 550};
    sfVector2f size = {100, 600};

    char_create->backgr = sfSprite_create();
    char_create->player = malloc(sizeof(char *) * 11);
    char_create->player[0] = '\0';
    backgr_txture = sfTexture_createFromFile
    ("resources/char_creation/backgr_char_creation.png", NULL);
    sfSprite_setTexture(char_create->backgr, backgr_txture, sfTrue);
    char_create->textinput = sfSprite_create();
    keyputs_txture = sfTexture_createFromFile
    ("resources/char_creation/textinput.png", NULL);
    sfSprite_setTexture(char_create->textinput, keyputs_txture, sfTrue);
    sfSprite_setPosition(char_create->textinput, keyputs_pos);
    finish_disp_char_creation(char_create, window, size);
    init_disp_char_creation_buttons(char_create, window);
}

void init_disp_char_creation_buttons(char_create_t *char_create,
sfRenderWindow *window)
{
    sfTexture *b_return_txture;
    sfTexture *b_start_txture;
    sfVector2f b_pos_return = {200, 800};
    sfVector2f b_pos_start = {1500, 800};
    sfVector2f textpos = {705, 540};

    char_create->plyr_char_pos = 0;
    char_create->button_start = sfSprite_create();
    b_start_txture = sfTexture_createFromFile
    ("resources/char_creation/create_b.png", NULL);
    sfSprite_setTexture(char_create->button_start, b_start_txture, sfTrue);
    sfSprite_setPosition(char_create->button_start, b_pos_start);
    char_create->button_return = sfSprite_create();
    b_return_txture = sfTexture_createFromFile
    ("resources/char_creation/return_b.png", NULL);
    sfSprite_setTexture(char_create->button_return, b_return_txture, sfTrue);
    sfSprite_setPosition(char_create->button_return, b_pos_return);
    create_text_char_creation(char_create, textpos);
    pikapika_charcreation(char_create);
}

int text_tweaks(sfRenderWindow *win, sfEvent event, char_create_t *char_create)
{
    if (my_str_event_is_validated(event) == 1 &&
    is_inside_here(char_create->textinput, win) == 1) {
        if (my_strlen(char_create->player) > 10)
            return (0);
        char_create->player[char_create->plyr_char_pos] = event.text.unicode;
        char_create->plyr_char_pos++;
        char_create->player[char_create->plyr_char_pos] = '\0';
        sfText_setString(char_create->keyputs, char_create->player);
    }
    if (is_inside_here(char_create->textinput, win) == 1) {
        if (event.key.code == sfKeyDelete || event.key.code == sfKeyBack) {
            char_create->player[char_create->plyr_char_pos] = '\0';
            if (char_create->plyr_char_pos == 0)
                return (0);
            char_create->plyr_char_pos--;
            char_create->player[char_create->plyr_char_pos] = '\0';
            sfText_setString(char_create->keyputs, char_create->player);
        }
    }
    return (0);
}

int create_perso(global_t *global)
{
    char_create_t *char_create = malloc(sizeof(char_create_t));

    char_create->a = 0;
    init_disp_char_creation(char_create, global->window.window);
    while (sfRenderWindow_isOpen(global->window.window) &&
    char_create->a == 0) {
        while (sfRenderWindow_pollEvent(global->window.window,
        &global->window.event))
            events(global->window.event, global->window.window, char_create);
        display_char_creation(char_create, global->window.window);
        sfRenderWindow_display(global->window.window);
    }
    free_car_creation(char_create);
    return (char_create->a);
}