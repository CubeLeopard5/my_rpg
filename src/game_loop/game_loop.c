/*
** EPITECH PROJECT, 2020
** game loop
** File description:
** the game main loop
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "game_loop.h"
#include "stdio.h"
#include "battle.h"
#include "function.h"
#include "intro.h"
#include "engine.h"

int perso(global_t *global)
{
    static int a = 0;

    a = create_perso(global);
    return (a);
}

int game_functions(global_t *global)
{
    int i = 0;

    game_scene_map(global);
    game_scene_inv(global);
    game_scene_pause(global);
    game_scene_battle(i, global);
    game_scene_final(global);
    if (!(sfRenderWindow_isOpen(global->window.window)))
        global->window.rtn_menu = -4;
    if (global->window.rtn_menu == -1)
        return (-1);
    if (global->window.rtn_menu == -4)
        return (-4);
    return (1);
}

int game_loop(global_t *global)
{
    intro(global);
    global->window.rtn_menu = perso(global);
    sfMusic_play(global->music);
    while (game_functions(global) == 1);
    if (global->window.rtn_menu == -1)
        return (1);
    if (global->window.rtn_menu == -4)
        return (4);
    return (0);
}