/*
** EPITECH PROJECT, 2020
** finish the character
** File description:
** rpg
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "function.h"
#include "stdio.h"
#include "sflib_f.h"
#include "char_create.h"
#include <library.h>


void finish_disp_char_creation(char_create_t *char_create,
sfRenderWindow *window, sfVector2f size)
{
    char_create->hover = sfRectangleShape_create();
    sfRectangleShape_setFillColor(char_create->hover, sfWhite);
    sfRectangleShape_setSize(char_create->hover, size);
    char_create->fonty = sfFont_createFromFile
    ("resources/char_creation/font.ttf");
}

void pikapika_charcreation(char_create_t *char_create)
{
    sfVector2f posiposi = {550, 20};
    sfTexture *pikapika_txturey;

    pikapika_txturey = sfTexture_createFromFile
    ("resources/char_creation/create_your_character.png", NULL);
    char_create->pikapikacreate = sfSprite_create();
    sfSprite_setTexture(char_create->pikapikacreate, pikapika_txturey, sfTrue);
    sfSprite_setPosition(char_create->pikapikacreate, posiposi);
}

void create_text_char_creation(char_create_t *char_create, sfVector2f textpos)
{
    char_create->keyputs = sfText_create();
    sfText_setFont(char_create->keyputs, char_create->fonty);
    sfText_setColor(char_create->keyputs, sfBlack);
    sfText_setCharacterSize(char_create->keyputs, 75);
    sfText_setPosition(char_create->keyputs, textpos);
}

void free_car_creation(char_create_t *char_create)
{
    sfSprite_destroy(char_create->pikapikacreate);
    sfSprite_destroy(char_create->backgr);
    sfSprite_destroy(char_create->button_return);
    sfSprite_destroy(char_create->button_start);
    sfSprite_destroy(char_create->textinput);
    sfRectangleShape_destroy(char_create->hover);
    sfText_destroy(char_create->keyputs);
    sfFont_destroy(char_create->fonty);
}