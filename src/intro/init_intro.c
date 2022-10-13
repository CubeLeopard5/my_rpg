/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_intro
*/

#include "intro.h"
#include "init.h"

sfText *set_text_center_to_center(sfText *text)
{
    sfFloatRect gb = sfText_getGlobalBounds(text);
    sfVector2f origin;

    origin.x = gb.width/2;
    origin.y = gb.height/ 2;
    sfText_setOrigin(text, origin);
    return (text);
}

static void init_text(global_t *global)
{
    sfVector2f pos;

    pos.x = 1920 / 2 + 100;
    pos.y = 900;
    global->intro.text = sfText_create();
    global->intro.font = sfFont_createFromFile("resources/fonts/8bit.ttf");
    sfText_setFont(global->intro.text, global->intro.font);
    sfText_setString(global->intro.text, "Pika?");
    sfText_setPosition(global->intro.text, pos);
    sfText_setCharacterSize(global->intro.text, 50);
    sfText_setColor(global->intro.text, sfBlack);
    global->intro.text = set_text_center_to_center(global->intro.text);
}

void init_pickachu(global_t *global)
{
    sfIntRect rect;
    sfVector2f pos = {.x = 1100, .y = 800};
    sfVector2f scale =  {.x = 1.5, .y = 1.5};

    rect.height = 128;
    rect.left = 0;
    rect.top = 0;
    rect.width = 128;
    global->intro.Pickachu = init_this_sprite("assets/images/pika_player.png",
    global);
    global->intro.Pickachu = set_player_origin(global->intro.Pickachu);
    sfSprite_setTextureRect(global->intro.Pickachu, rect);
    sfSprite_setScale(global->intro.Pickachu, scale);
    sfSprite_setPosition(global->intro.Pickachu, pos);
}

void init_intro(global_t *global)
{
    init_pickachu(global);
    global->intro.background = init_this_sprite("assets/intro/background.jpg",
    global);
    init_text(global);
}

