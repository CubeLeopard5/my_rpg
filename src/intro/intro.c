/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** intro_loop
*/

#include "struct.h"
#include "SFML/Graphics.h"
#include "SFML/Audio.h"
#include "intro.h"
#include "function.h"
#include "engine.h"

sfText *change_text(sfText *text, char *str)
{
    sfText_setString(text, str);
    text = set_text_center_to_center(text);
    return (text);
}

sfSprite *turn_pika(sfSprite *sprite, int dir)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    rect.top = dir * 128;
    sfSprite_setTextureRect(sprite, rect);
    return (sprite);
}

int intro_loop(global_t *global)
{
    static int intro_state = 0;
    static float time_float = 0;

    if (time_float == 0)
        compare_time(global->time.clock, &time_float, 0);
    if (intro_state == 9 &&
    compare_time(global->time.clock, &time_float, 1500) == 1)
        return (1);
    sfRenderWindow_clear(global->window.window, sfBlack);
    intro_steps(global, &intro_state, &time_float);
    sfRenderWindow_drawSprite(global->window.window,
    global->intro.background, NULL);
    sfRenderWindow_drawSprite(global->window.window,
    global->intro.Pickachu, NULL);
    sfRenderWindow_drawText(global->window.window, global->intro.text, NULL);
    sfRenderWindow_display(global->window.window);
    return (0);
}

void intro(global_t *global)
{
    init_intro(global);
    while (sfRenderWindow_isOpen(global->window.window) &&
    intro_events(global) == 0) {
        if (intro_loop(global) == 1) {
            break;
        }
    }
}