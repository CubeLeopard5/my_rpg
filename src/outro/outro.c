/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** outro
*/

#include "struct.h"
#include "SFML/Graphics.h"
#include "SFML/Audio.h"
#include "intro.h"
#include "function.h"
#include "engine.h"

void init_outro(global_t *global)
{
    sfVector2f pos;

    pos.x = 1920 / 2 + 100;
    pos.y = 900;
    global->outro.background = init_this_sprite
    ("assets/intro/outro.jpg", global);
    global->outro.text = sfText_create();
    global->outro.font = sfFont_createFromFile("resources/fonts/8bit.ttf");
    sfText_setFont(global->outro.text, global->outro.font);
    sfText_setString(global->outro.text, "Pika?");
    sfText_setColor(global->outro.text, sfBlack);
    sfText_setCharacterSize(global->outro.text, 70);
    sfText_setPosition(global->outro.text, pos);
    global->outro.otaria = init_this_sprite("assets/NPC/17.png", global);
    pos.x = 800;
    pos.y = 500;
    sfSprite_setPosition(global->outro.otaria, pos);
}

void outro_display(global_t *global)
{
    sfVector2f pos = {.x = 0, .y = 0};

    sfSprite_setPosition(global->outro.background, pos);
    sfRenderWindow_drawSprite(global->window.window,
    global->outro.background, NULL);
    sfRenderWindow_drawSprite(global->window.window,
    global->outro.otaria, NULL);
    sfRenderWindow_drawText(global->window.window, global->outro.text, NULL);
    sfRenderWindow_display(global->window.window);
}

int outro_loop(global_t *global)
{
    static int intro_state = 0;
    static float time_float = 0;

    if (time_float == 0)
        compare_time(global->time.clock, &time_float, 0);
    if (intro_state == 5 &&
    compare_time(global->time.clock, &time_float, 1500) == 1)
        return (1);
    outro_steps(global, &intro_state, &time_float);
    sfRenderWindow_clear(global->window.window, sfBlack);
    outro_display(global);
    return (0);
}

void outro(global_t *global)
{
    init_outro(global);
    while (outro_loop(global) == 0);
}