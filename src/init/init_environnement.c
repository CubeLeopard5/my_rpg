/*
** EPITECH PROJECT, 2020
** init environnement
** File description:
** init the different env types
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "init.h"

void init_forest(global_t *global, int i)
{
    global->env_spr[i][0] = init_this_sprite("assets/tiles/1/grass.png",
    global);
    global->env_spr[i][1] = init_this_sprite("assets/tiles/1/path.png",
    global);
    global->env_spr[i][2] = init_this_sprite("assets/tiles/1/tree.png",
    global);
    global->env_spr[i][3] = init_this_sprite("assets/tiles/1/high_grass.png",
    global);
    global->env_spr[i][4] = init_this_sprite("assets/tiles/1/blue_flower.png",
    global);
    global->env_spr[i][5] = init_this_sprite("assets/tiles/1/pink_flower.png",
    global);
    global->env_spr[i][6] = init_this_sprite("assets/tiles/1/water.png",
    global);
    global->env_spr[i][7] = init_this_sprite("assets/tiles/1/red_flower.png",
    global);
    global->env_spr[i][8] = init_this_sprite("assets/tiles/1/rock.png",
    global);
    global->env_spr[i][9] = init_this_sprite("assets/tiles/1/plank.jpg",
    global);
}

void init_environnement(global_t *global)
{
    global->env_spr = malloc(sizeof(sfSprite **) * 5);
    for (int i = 0; i < 4; i++) {
        global->env_spr[i] = malloc(sizeof(sfSprite *) * 10);
    }
    init_forest(global, 1);
}